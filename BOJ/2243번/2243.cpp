#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int MAX_CANDY = 1000000;
vector<int> tree;

void update(int index, int num, int size)
{
    index += size / 2;
    tree[index] += num;

    while (index > 1)
    {
        index /= 2;
        tree[index] = tree[index * 2] + tree[index * 2 + 1];
    }
}

int get_candy(int node, int cnt, int start, int end, int size)
{
    if (start == end)
    {
        update(start, -1, size);
        return start + 1;
    }
    int mid = (start + end) / 2;

    if (tree[node * 2] > 0 && cnt <= tree[node * 2])
    {
        return get_candy(node * 2, cnt, start, mid, size);
    }
    else
    {
        return get_candy(node * 2 + 1, cnt - tree[node * 2], mid + 1, end, size);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int height = (int) ceil(log2(MAX_CANDY));
    int tree_size = (1 << (height + 1));
    tree.assign(tree_size, 0);
    
    int N;
    cin >> N;

    int A, B, C;
    
    while (N--)
    {
        cin >> A;

        if (A == 1)
        {
            cin >> B;
            cout << get_candy(1, B, 0, tree_size / 2 - 1, tree_size) << '\n';
        }
        else
        {
            cin >> B >> C;
            update(B - 1, C, tree_size);
        }
    }

    return 0;
}