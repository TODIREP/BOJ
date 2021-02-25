#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct number
{
    int num, index;
    bool operator<(const number &a) const
    {
        return num < a.num;
    }
};

vector<int> tree;

void init(int size)
{
    for (int i = size / 2 - 1; i > 0; i--)
    {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

int sum(int node, int left, int right, int start, int end)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, left, right, start, mid) + sum(node * 2 + 1, left, right, mid + 1, end);
}

void check(int index, int size)
{
    index += size / 2;
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

    int N, input;
    cin >> N;
    vector<number> data(N);
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        data[i] = {input, i};
    }
    sort(data.begin(), data.end());

    int height = (int) ceil(log2(N));
    int tree_size = (1 << (height + 1));

    tree.assign(tree_size, 0);
    for (int i = 0; i < N; i++)
    {
        tree[(tree_size / 2) + i] = 1;
    }
    init(tree_size);

    int left = 0, right = N - 1;

    for (int i = 0; i < N; i++)
    {
        int change = 0;
        if (i % 2 == 0)
        {
            if (data[left].index > 0)
            {
                change = sum(1, 0, data[left].index - 1, 0, tree_size / 2 - 1);
            }
            check(data[left].index, tree_size);
            left++;
        }
        else
        {
            if (data[right].index < N - 1)
            {
                change = sum(1, data[right].index + 1, tree_size / 2 - 1, 0, tree_size / 2 - 1);
            }
            check(data[right].index, tree_size);
            right--;
        }
        cout << change << '\n';
    }

    return 0;
}