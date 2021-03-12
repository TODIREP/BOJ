#include <iostream>
using namespace std;

int tree[262145], tree_size;

void init(int size = tree_size)
{
    for (int index = size - 1; index > 0; index--)
    {
        tree[index] = tree[index * 2] + tree[index * 2 + 1];
    }
}

int get_index(int node, int target, int start, int end)
{
    if (start == end)
    {
        return start;
    }
    int mid = (start + end) / 2;

    if (target <= tree[node * 2])
    {
        return get_index(node * 2, target, start, mid);
    }
    else
    {
        return get_index(node * 2 + 1, target - tree[node * 2], mid + 1, end);
    }
}

void update(int index, int size = tree_size)
{
    index += size;
    tree[index] = 0;

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

    int N, K;
    cin >> N >> K;

    tree_size = 1;
    while (tree_size < N)
    {
        tree_size *= 2;
    }

    for (int i = 0; i < N; i++)
    {
        tree[tree_size + i] = 1;
    }
    init();

    int start = K - 1, nxt = K, res;
    update(K - 1);
    cout << '<' << start + 1;
    
    for (int i = 1; i < N; i++)
    {
        cout << ", ";
        nxt += K - 1;
        if (nxt > tree[1])
        {
            nxt %= tree[1];
            if (nxt == 0) nxt = tree[1];
        }

        res = get_index(1, nxt, 0, tree_size - 1);

        update(res);
        start = res;
        cout << start + 1;
    }
    cout << '>';

    return 0;
}