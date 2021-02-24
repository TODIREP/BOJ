#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using lint = long long;
lint mod = 1000000007;

vector<lint> tree;
lint cal(lint a, lint b)
{
    return a * b % mod;
}

void init(int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        tree[i] = cal(tree[i * 2], tree[i * 2 + 1]);
    }
}

lint sum(int node, int left, int right, int start, int end)
{
    if (left > end || right < start) return 1;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return cal(sum(node * 2, left, right, start, mid), sum(node * 2 + 1, left, right, mid + 1, end));
}

void update(int index, int size, lint num)
{
    index += size;
    tree[index] = num;
    while (index > 1)
    {
        index /= 2;
        tree[index] = cal(tree[index * 2], tree[index * 2 + 1]);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, K;
    cin >> N >> M >> K;

    int height = (int) ceil(log2(N));
    int tree_size = (1 << (height + 1));
    int leaf_size = (1 << height);
    tree.assign(tree_size, 1);

    for (int i = 0; i < N; i++) cin >> tree[leaf_size + i];
    init(leaf_size);
    
    M += K;
    lint A, B, C;
    while (M--)
    {
        cin >> A >> B >> C;
        if (A == 1) update(B - 1, leaf_size, C);
        else cout << sum(1, B - 1, C - 1, 0, leaf_size - 1) % mod << '\n';
    }
    return 0;
}