#include <iostream>
#include <vector>
using namespace std;

bool vis[10001];
vector<pair<int, int> > tree[10001];
int answer = 0, point = 0;

void search(int cur, int len)
{
    if (answer < len)
    {
        answer = len;
        point = cur;
    }

    for (auto nxt : tree[cur])
    {
        if (vis[nxt.first]) continue;
        vis[nxt.first] = true;
        search(nxt.first, len + nxt.second);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, A, B, C;
    cin >> N;
    for (int i = 1; i <= N; i++) vis[i] = false;
    for (int i = 1; i < N; i++)
    {
        cin >> A >> B >> C;
        tree[A].push_back({B, C});
        tree[B].push_back({A, C});
    }

    vis[1] = true;
    search(1, 0);
    answer = 0;
    for (int i = 1; i <= N; i++) vis[i] = false;

    vis[point] = true;
    search(point, 0);
    cout << answer;
    return 0;
}