#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[2];

void init(int size)
{
    for (int i = size / 2 - 1; i > 0; i--)
    {
        tree[0][i] = tree[0][i * 2] + tree[0][i * 2 + 1];
        tree[1][i] = tree[1][i * 2] + tree[1][i * 2 + 1];
    }
}

pair<int, int> cnt(int node, int left, int right, int start, int end)
{
    if (left > end || right < start) return {0, 0};
    if (left <= start && end <= right) return {tree[0][node], tree[1][node]};
    int mid = (start + end) / 2;

    auto L = cnt(node * 2, left, right, start, mid);
    auto R = cnt(node * 2 + 1, left, right, mid + 1, end);

    return {L.first + R.first, L.second + R.second};
}

void update(int index, int num, int size)
{
    index += size / 2;
    
    if (num % 2 == 0)
    {
        tree[0][index] = 1;
        tree[1][index] = 0;
    }
    else
    {
        tree[0][index] = 0;
        tree[1][index] = 1;
    }

    while (index > 1)
    {
        index /= 2;

        tree[0][index] = tree[0][index * 2] + tree[0][index * 2 + 1];
        tree[1][index] = tree[1][index * 2] + tree[1][index * 2 + 1];
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int tree_size = 1;
    while (tree_size < N)
    {
        tree_size *= 2;
    }
    tree_size *= 2;

    tree[0].assign(tree_size, 0);
    tree[1].assign(tree_size, 0);

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        tree[num % 2][(tree_size / 2) + i] = 1;
    }
    init(tree_size);

    int M;
    cin >> M;

    int P, I, R;
    while (M--)
    {
        cin >> P >> I >> R;

        if (P == 1)
        {
            update(I - 1, R, tree_size);
        }
        else
        {
            auto res = cnt(1, I - 1, R - 1, 0, tree_size / 2 - 1);
            if (P == 2) cout << res.first << '\n';
            else cout << res.second << '\n';
        }
    }

    return 0;
}