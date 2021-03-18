#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int sum(vector<int> &t, int node, int left, int right, int start, int end)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return t[node];
    int mid = (start + end) / 2;
    return max(sum(t, node * 2, left, right, start, mid),
             sum(t, node * 2 + 1, left, right, mid + 1, end));
}

void update(vector<int> &t, int index, int num, int size)
{
    index += size;
    t[index] = num;

    while (index > 1)
    {
        index /= 2;
        t[index] = max(t[index * 2], t[index * 2 + 1]);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, number;
    cin >> N;

    vector<pair<int, int>> input(N);
    for (int i = 0; i < N; i++)
    {
        cin >> number;
        input[i] = {number, i};
    }
    sort(input.begin(), input.end(), cmp);

    int tree_size = 1;
    while (tree_size < N)
    {
        tree_size *= 2;
    }
    vector<int> tree(tree_size * 2, 0);

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        int s = sum(tree, 1, 0, input[i].second, 0, tree_size - 1) + 1;
        update(tree, input[i].second, s, tree_size);
        answer = max(answer, s);
    }

    cout << N - answer;

    return 0;
}