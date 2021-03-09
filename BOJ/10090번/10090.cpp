#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using lint = long long;

vector<lint> tree;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

lint sum(int node, int left, int right, int start, int end)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, left, right, start, mid) + sum(node * 2 + 1, left, right, mid + 1, end);
}

void update(int index, int size)
{
    index += size;
    tree[index] = 1;

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

    int N;
    cin >> N;

    int tree_size = 1;
    while (tree_size < N)
    {
        tree_size *= 2;
    }
    tree.assign(tree_size * 2, 0);

    vector<pair<int, int>> target(N);

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        target[i] = {num, i};
    }
    sort(target.begin(), target.end());

    lint answer = 0;

    for (int i = 0; i < N; i++)
    {
        update(target[i].second, tree_size);
        answer += sum(1, target[i].second + 1, tree_size - 1, 0, tree_size - 1);
    }

    cout << answer;

    return 0;
}