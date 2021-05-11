#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;
int tree_size = 1;
void init()
{
    for (int i = tree_size - 1; i > 0; i--) tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

void update(int index)
{
    index += tree_size;
    tree[index] = 0;
    while (index > 1)
    {
        index /= 2;
        tree[index] = tree[index * 2] + tree[index * 2 + 1];
    }
}

int getIndex(int number, int node = 1, int start = 0, int end = tree_size - 1)
{
    if (start == end)
    {
        update(start);
        return start;
    }
    int mid = (start + end) / 2;

    if (tree[node * 2] >= number)
    {
        return getIndex(number, node * 2, start, mid);
    }
    else
    {
        return getIndex(number - tree[node * 2], node * 2 + 1, mid + 1, end);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, input;
    cin >> N;
    while (tree_size < N) tree_size *= 2;
    tree.assign(tree_size * 2, 1);
    init();
    vector<int> result(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        int ans = getIndex(input + 1);
        result[ans] = i + 1;
    }

    for (int i = 0; i < N; i++) cout << result[i] << '\n';
    return 0;
}