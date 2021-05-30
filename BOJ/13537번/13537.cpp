#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int tree_size = 1 << 20;
vector<int> tree[tree_size];
void init()
{
    for (int i = tree_size / 2 - 1; i > 0; i--)
    {
        vector<int> &l = tree[i * 2], &r = tree[i * 2 + 1];
        tree[i].resize(l.size() + r.size());
        merge(l.begin(), l.end(), r.begin(), r.end(), tree[i].begin());
    }
}
int get_count(int left, int right, int number, int node = 1, int start = 0, int end = tree_size / 2 - 1)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), number);
    int mid = (start + end) / 2;
    return get_count(left, right, number, node * 2, start, mid) + get_count(left, right, number, node * 2 + 1, mid + 1, end);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t, num;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> num;
        tree[tree_size / 2 + i].push_back(num);
    }
    init();

    int m, i, j, k;
    cin >> m;

    for (int p = 0; p < m; p++)
    {
        cin >> i >> j >> k;
        cout << get_count(i - 1, j - 1, k) << '\n';
    }
    return 0;
}