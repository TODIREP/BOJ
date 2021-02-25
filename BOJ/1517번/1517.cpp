#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using lint = long long;

struct number
{
    lint num, index;
    bool operator<(const number &a) const
    {
        if (num == a.num)
        {
            return index < a.index;
        }
        return num < a.num;
    }
};

vector<lint> tree;

void init(lint size)
{
    for (lint i = size / 2 - 1; i > 0; i--)
    {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

lint sum(lint node, lint left, lint right, lint start, lint end)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    lint mid = (start + end) / 2;
    return sum(node * 2, left, right, start, mid) + sum(node * 2 + 1, left, right, mid + 1, end);
}

void check(lint index, lint size)
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

    lint N, input;
    cin >> N;
    vector<number> data(N);
    for (lint i = 0; i < N; i++)
    {
        cin >> input;
        data[i] = {input, i};
    }
    sort(data.begin(), data.end());

    lint height = (lint) ceil(log2(N));
    lint tree_size = (1 << (height + 1));

    tree.assign(tree_size, 1);
    init(tree_size);

    lint res = 0;
    for (lint i = 0; i < N; i++)
    {
        if (data[i].index > 0)
        {
            res += sum(1, 0, data[i].index - 1, 0, tree_size / 2 - 1);
        }
        check(data[i].index, tree_size);
    }

    cout << res;

    return 0;
}