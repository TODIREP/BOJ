#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int LIMITS = 1e9 + 1;
vector<int> tree;

void init(int size)
{
    for (int i = size / 2 - 1; i > 0; i--)
    {
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
    }
}

int get_min(int node, int left, int right, int start, int end)
{
    if (left > end || right < start) return LIMITS;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return min(get_min(node * 2, left, right, start , mid), get_min(node * 2 + 1, left, right, mid + 1, end));
}

void update(int index, int num, int size)
{
    index += size / 2;
    tree[index] = num;

    while (index > 1)
    {
        index /= 2;
        tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int height = (int) ceil(log2(N));
    int tree_size = (1 << (height + 1));
    tree.assign(tree_size, LIMITS);

    for (int i = 0; i < N; i++)
    {
        cin >> tree[(tree_size / 2) + i];
    }
    init(tree_size);

    int M;
    cin >> M;

    int P;

    while (M--)
    {
        cin >> P;

        if (P == 1)
        {
            int I, V;
            cin >> I >> V;
            update(I - 1, V, tree_size);
        }
        else
        {
            int I, J;
            cin >> I >> J;
            cout << get_min(1, I - 1, J - 1, 0, tree_size / 2 - 1) << '\n';
        }
    }

    return 0;
}