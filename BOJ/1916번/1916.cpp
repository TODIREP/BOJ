#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 100000002;
struct course {
    int start;
    int time;
    bool operator<(const course &a) const { return time > a.time; }
};
vector<int> dis;
vector<vector<course > > node;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N, M;
    cin >> N >> M;

    dis.assign(N + 2, INF);
    node.resize(N + 2);

    int a, b, c;
    while (M--) {
        cin >> a >> b >> c;
        node[a].push_back({b, c});
    }

    int S, D;
    cin >> S >> D;

    dis[S] = 0;
    priority_queue<course > q;
    q.push({S, dis[S]});

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();

        if (cur.time != dis[cur.start]) continue;

        for (auto nxt: node[cur.start]) {
            int distance = dis[cur.start] + nxt.time;

            if (distance < dis[nxt.start]) {
                dis[nxt.start] = distance;
                q.push({nxt.start, dis[nxt.start]});
            }
        }
    }
    cout << dis[D];
    return 0;
}