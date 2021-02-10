#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 300000;
struct info {
    int link;
    int weight;
    bool operator<(const info &a) const { return weight > a.weight; }
};
vector<int> dis;
vector<vector<info > > node;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int V, E;
    cin >> V >> E;
    node.resize(V + 2);
    dis.assign(V + 2, INF);

    int K;
    cin >> K;
    dis[K] = 0;

    int u, v, w;
    while (E--) {
        cin >> u >> v >> w;
        node[u].push_back({v, w});
    }

    priority_queue<info > q;
    q.push({K, 0});

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();

        if (cur.weight != dis[cur.link]) continue;

        for (auto nxt : node[cur.link]) {
            int distance = dis[cur.link] + nxt.weight;
            if (distance < dis[nxt.link]) {
                dis[nxt.link] = distance;
                q.push({nxt.link, distance});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dis[i] >= INF) cout << "INF";
        else cout << dis[i];
        cout << "\n";
    }
    return 0;
}