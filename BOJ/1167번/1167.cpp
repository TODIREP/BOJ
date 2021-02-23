#include <iostream>
#include <vector>
using namespace std;

bool vis[100001];
vector<pair<int, int> > tree[100001];
int res = 0, point = 0;

void search(int cur, int len)
{
    if (res < len)
    {
        res = len;
        point = cur;
    }

    for (auto nxt: tree[cur])
    {
        if (vis[nxt.first]) continue;
        vis[nxt.first] = true;
        search(nxt.first, len + nxt.second);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int V, N, E, L;
    cin >> V;

    for (int i = 0; i < V; i++)
    {
        cin >> N;
        while (cin >> E)
        {
            if (E == -1) break;
            cin >> L;

            tree[N].push_back({E, L});
        }
    }

    vis[1] = true;
    search(1, 0);
    res = 0;
    for (int i = 1; i <= V; i++) vis[i] = false;

    vis[point] = true;
    search(point, 0);
    cout << res;
    return 0;
}