#include <iostream>
#include <vector>
using namespace std;

const int max_size = 2000000;

int get_index(vector<int> &tree, int num, int start, int end, int node)
{
    if (start == end) return start;
    int mid = (start + end) / 2;
    if (tree[node * 2] >= num) return get_index(tree, num, start, mid, node * 2);
    return get_index(tree, num - tree[node * 2], mid + 1, end, node * 2 + 1);
}

void update(vector<int> &tree, int index, int number, int size)
{
    index += size;
    tree[index] += number;
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

    int N, T, X;
    cin >> N;

    int tree_size = 1;
    while (tree_size < max_size) tree_size *= 2;
    vector<int> tree(tree_size * 2, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> T >> X;
        if (T == 1) update(tree, X - 1, 1, tree_size);
        else
        {
            int res = get_index(tree, X, 0, tree_size - 1, 1);
            update(tree, res, -1, tree_size);
            cout << res + 1 << '\n';
        }
    }
    return 0;
}