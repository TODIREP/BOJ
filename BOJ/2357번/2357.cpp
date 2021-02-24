#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int LIMITS = 1e9 + 1;
vector<int> tree[2];

void init(int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        tree[0][i] = min(tree[0][i * 2], tree[0][i * 2 + 1]);
        tree[1][i] = max(tree[1][i * 2], tree[1][i * 2 + 1]);
    }
}

int get_min(int node, int left, int right, int start, int end)
{
    if (left > end || right < start) return LIMITS;
    if (left <= start && end <= right) return tree[0][node];
    int mid = (start + end) / 2;
    return min(get_min(node * 2, left, right, start, mid)
            , get_min(node * 2 + 1, left, right, mid + 1, end));
}

int get_max(int node, int left, int right, int start, int end)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[1][node];
    int mid = (start + end) / 2;
    return max(get_max(node * 2, left, right, start, mid)
            , get_max(node * 2 + 1, left, right, mid + 1, end));
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, num;
    cin >> N >> M;

    int height = (int) ceil(log2(N));
    int tree_size = (1 << (height + 1));
    int leaf_size = (1 << height);

    tree[0].assign(tree_size, LIMITS);
    tree[1].assign(tree_size, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        tree[0][leaf_size + i] = num;
        tree[1][leaf_size + i] = num;
    }

    init(leaf_size);

    int A, B;
    while (M--)
    {
        cin >> A >> B;
        cout << get_min(1, A - 1, B - 1, 0, leaf_size - 1) << " ";
        cout << get_max(1, A - 1, B - 1, 0, leaf_size - 1) << '\n';
    }
    return 0;
}