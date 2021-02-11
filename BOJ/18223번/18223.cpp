#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 60000000;
struct link {
    int start;
    int time;
    bool operator<(const link &a) const { return time > a.time; }
};
vector<int> dis;
vector<vector<link > > node;

int search(int S, int D, int len) {
    dis.assign(len + 2, INF);
    priority_queue<link > q;
    dis[S] = 0;
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
    return dis[D];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int V, E, P;
    cin >> V >> E >> P;
    node.resize(V + 2);

    int a, b, c;
    while (E--) {
        cin >> a >> b >> c;
        node[a].push_back({b, c});
        node[b].push_back({a, c});
    }
    int saver = search(1, P, V) + search(P, V, V);
    int direct = search(1, V, V);
    cout << (saver <= direct ? "SAVE HIM" : "GOOD BYE");
    return 0;
}