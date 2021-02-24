#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using lint = long long;

vector<lint> tree;

void init(int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

lint sum(int node, int left, int right, int start, int end)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, left, right, start, mid) + sum(node * 2 + 1, left, right, mid + 1, end);
}

void update(int index, int size, lint num)
{
    index += size;
    tree[index] = num;
    while (index > 1)
    {
        index /= 2;
        tree[index] = tree[index * 2] + tree[index * 2 + 1];
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    int height = (int) ceil(log2(N));
    int tree_size = (1 << (height + 1));
    int leaf_size = (1 << height);
    tree.assign(tree_size, 0);

    for (int i = 0; i < N; i++) cin >> tree[leaf_size + i];

    init(leaf_size);

    int X, Y, A, B;
    while (Q--)
    {
        cin >> X >> Y >> A >> B;
        if (X < Y) cout << sum(1, X - 1, Y - 1, 0, leaf_size - 1) << '\n';
        else cout << sum(1, Y - 1, X - 1, 0, leaf_size - 1) << '\n';
        update(A - 1, leaf_size, B);
    }
    return 0;
}