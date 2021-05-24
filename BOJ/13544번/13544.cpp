#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int tree_size = 1 << 18;

vector<int> tree[tree_size];

void init()
{
    for (int i = tree_size / 2 - 1; i > 0; i--)
    {
        tree[i].resize(tree[i * 2].size() + tree[i * 2 + 1].size());
        merge(tree[i * 2].begin(), tree[i * 2].end(), 
        tree[i * 2 + 1].begin(), tree[i * 2 + 1].end(), tree[i].begin());
    }
}

int get_number(int left, int right, int level, int node = 1, int start = 0, int end = tree_size / 2 - 1)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), level);
    int mid = (start + end) / 2;
    return get_number(left, right, level, node * 2, start, mid)
        + get_number(left, right, level, node * 2 + 1, mid + 1, end);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, num;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        tree[tree_size / 2 + i].push_back(num);
    }
    init();

    int M, ans = 0, a, b, c;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        ans = get_number((a ^ ans) - 1, (b ^ ans) - 1, c ^ ans);
        cout << ans << '\n';
    }
    return 0;
}