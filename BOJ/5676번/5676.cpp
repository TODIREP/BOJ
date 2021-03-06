#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int get_absol(int target)
{
    if (target > 0) return 1;
    else if (target < 0) return -1;
    else return 0;
}

void init(vector<int> &tree, int size)
{
    for (int i = size / 2 - 1; i > 0; i--)
    {
        tree[i] = tree[i * 2] * tree[i * 2 + 1];
    }
}

int get_value(vector<int> &tree, int node, int left, int right, int start, int end)
{
    if (left > end || right < start) return 1;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return get_value(tree, node * 2, left, right, start, mid) * get_value(tree, node * 2 + 1, left, right, mid + 1, end);
}

void update(vector<int> &tree, int index, int num, int size)
{
    index += size / 2;
    tree[index] = get_absol(num);

    while (index > 1)
    {
        index /= 2;
        tree[index] = tree[index * 2] * tree[index * 2 + 1];
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, K;
    while(cin >> N >> K)
    {
        int height = (int) ceil(log2(N));
        int tree_size = (1 << (height + 1));
        vector<int> tree(tree_size, 1);

        for (int i = 0; i < N; i++)
        {
            cin >> tree[(tree_size / 2) + i];
            tree[(tree_size / 2) + i] = get_absol(tree[(tree_size / 2) + i]);
        }
        init(tree, tree_size);

        char oper[2];
        while (K--)
        {
            cin >> oper;
            if (oper[0] == 'C')
            {
                int I, V;
                cin >> I >> V;
                V = get_absol(V);
                update(tree, I - 1, V, tree_size);
            }
            else
            {
                int I, J;
                cin >> I >> J;
                int res = get_value(tree, 1, I - 1, J - 1, 0, tree_size / 2 - 1);
                if (res == 0) cout << '0';
                else if (res > 0) cout << '+';
                else cout << '-';
            }
        }
        cout << '\n';
    }

    return 0;
}