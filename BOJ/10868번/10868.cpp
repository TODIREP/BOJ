#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int LIMITS = 1e9 + 1;
void init(vector<int> &tree, int size)
{
    for (int i = size / 2 - 1; i > 0; i--)
    {
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
    }
}

int get_min(vector<int> &tree, int node, int left, int right, int start, int end)
{
    if (left > end || right < start) return LIMITS;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return min(get_min(tree, node * 2, left, right, start, mid)
            , get_min(tree, node * 2 + 1, left, right, mid + 1, end));
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int height = (int) ceil(log2(N));
    int tree_size = (1 << (height + 1));
    vector<int> tree(tree_size, LIMITS);

    for (int i = 0; i < N; i++) cin >> tree[(tree_size / 2) + i];

    init(tree, tree_size);

    int A, B;
    while (M--)
    {
        cin >> A >> B;
        if (A < B) cout << get_min(tree, 1, A - 1, B - 1, 0, tree_size / 2 - 1);
        else cout << get_min(tree, 1, B - 1, A - 1, 0, tree_size / 2 - 1);
        cout << '\n';
    }
    return 0;
}