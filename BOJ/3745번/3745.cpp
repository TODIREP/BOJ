#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int sum(vector<int> &tree, int node, int left, int right, int start, int end)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return max(sum(tree, node * 2, left, right, start, mid),
         sum(tree, node * 2 + 1, left, right, mid + 1, end));
}

void update(vector<int> &tree, int index, int num, int size)
{
    index += size;
    tree[index] = num;

    while (index > 1)
    {
        index /= 2;
        tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    while(cin >> N)
    {
        int num;
        vector<pair<int, int>> input(N);
        for (int i = 0; i < N; i++)
        {
            cin >> num;
            input[i] = {num, i};
        }
        sort(input.begin(), input.end(), cmp);

        int tree_size = 1;
        while (tree_size < N)
        {
            tree_size *= 2;
        }
        vector<int> tree(tree_size * 2, 0);

        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            int len = sum(tree, 1, 0, input[i].second, 0, tree_size - 1) + 1;
            update(tree, input[i].second, len, tree_size);
            ans = max(ans, len);
        }
        cout << ans << '\n';
    }

    return 0;
}