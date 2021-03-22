#include <iostream>
#include <cstring>
using namespace std;
using lint = long long;

lint root[100002];
int cut[100002];
pair<int, int> link[100002];
bool check[100002];

lint find_root(lint n)
{
    if (root[n] < 0) return n;
    return root[n] = find_root(root[n]);
}

lint union_root(lint a, lint b)
{
    a = find_root(a);
    b = find_root(b);
    if (a == b) return 0;
    lint bound = root[a] * root[b];
    root[a] += root[b];
    root[b] = a;
    return bound;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(root, -1, sizeof(root));
    int N, M, Q;
    cin >> N >> M >> Q;

    int X, Y;
    for (int i = 1; i <= M; i++)
    {
        cin >> X >> Y;
        link[i] = {X, Y};
    }

    for (int i = 0; i < Q; i++)
    {
        cin >> cut[i];
        check[cut[i]] = true;
    }

    for (int i = 1; i <= M; i++)
    {
        if (!check[i])
        {
            union_root(link[i].first, link[i].second);
        }
    }

    lint answer = 0;
    for (int i = M - 1; i >= 0; i--)
    {
        answer += union_root(link[cut[i]].first, link[cut[i]].second);;
    }

    cout << answer;

    return 0;
}