#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int NUM_LIMITS = 1e9 + 1, IDX_LIMITS = 100001;

vector<pair<int, int> > tree;

pair<int, int> cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        if (a.second < b.second) return a;
        return b;
    }
    if (a.first < b.first) return a;
    return b;
}

void init(int size)
{
    for (int i = size / 2 - 1; i > 0; i--)
    {
        tree[i] = cmp(tree[i * 2], tree[i * 2 + 1]);
    }
}

pair<int, int> get_min(int node, int left, int right, int start, int end)
{
    if (left > end || right < start) return {NUM_LIMITS, IDX_LIMITS};
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return cmp(get_min(node * 2, left, right, start, mid)
            , get_min(node * 2 + 1, left, right, mid + 1, end));
}

void update(int index, int size, int num)
{
    index += size / 2;
    tree[index].first = num;

    while (index > 1)
    {
        index /= 2;
        tree[index] = cmp(tree[index * 2], tree[index * 2 + 1]);
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
    tree.assign(tree_size, {NUM_LIMITS, IDX_LIMITS});

    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        tree[(tree_size / 2) + i] = {input, i + 1};
    }

    init(tree_size);

    int M;
    cin >> M;

    int X;
    while (M--)
    {
        cin >> X;

        if (X == 1)
        {
            int I, V;
            cin >> I >> V;
            update(I - 1, tree_size, V);
        }
        else
        {
            cout << tree[1].second << '\n';
        }
    }
    return 0;
}