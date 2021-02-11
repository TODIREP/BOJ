#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct link {
    int start;
    int weight;
    bool operator<(const link &a) const { return weight > a.weight; }
};
int INF = 1000000;
vector<int> dis;
vector<vector<link > > node;

int search(int S, int D, int len) {
    dis.assign(len + 2, INF);
    dis[S] = 0;
    priority_queue<link > q;
    q.push({S, dis[S]});

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();

        if (cur.weight != dis[cur.start]) continue;

        for (auto nxt : node[cur.start]) {
            int distance = dis[cur.start] + nxt.weight;

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

    int N, E;
    cin >> N >> E;
    node.resize(N + 2);

    int a, b, c;
    while (E--) {
        cin >> a >> b >> c;
        node[a].push_back({b, c});
        node[b].push_back({a, c});
    }

    int V1, V2;
    cin >> V1 >> V2;
    int res1 = search(1, V1, N) + search(V1, V2, N) + search(V2, N, N);
    int res2 = search(1, V2, N) + search(V2, V1, N) + search(V1, N, N);
    int res = min(res1, res2);
    cout << (res >= INF ? -1 : res);
    return 0;
}