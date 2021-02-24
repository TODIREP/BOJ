#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using lint = long long;

vector<lint> tree;
lint sum(int node, int left, int right, int start, int end)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, left, right, start, mid)
         + sum(node * 2 + 1, left, right, mid + 1, end);
}

void modify(int index, int size, lint num)
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

    int N, M;
    cin >> N >> M;

    int height = (int) ceil(log2(N));
    int tree_size = (1 << (height + 1));
    int leaf_size = (1 << height);

    tree.assign(tree_size, 0);

    lint P, I, K;
    while (M--)
    {
        cin >> P >> I >> K;
        if (P == 0) {
            if (K < I) cout << sum(1, K - 1, I - 1, 0, leaf_size - 1) << '\n';
            else cout << sum(1, I - 1, K - 1, 0, leaf_size - 1) << '\n';
        }
        else modify(I - 1, leaf_size, K);
    }
    return 0;
}