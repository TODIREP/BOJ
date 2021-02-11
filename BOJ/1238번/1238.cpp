#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 10000004;
struct link {
    int cur;
    int time;
    bool operator<(const link &a) const { return time > a.time; }
};
vector<int> dis;
vector<vector<link > > node;

int search(int S, int D, int area) {
    dis.assign(area + 2, INF);
    priority_queue<link > q;
    dis[S] = 0;
    q.push({S, dis[S]});

    while (!q.empty()) {
        auto start = q.top();
        q.pop();

        if (start.time != dis[start.cur]) continue;

        for (auto nxt: node[start.cur]) {
            int distance = dis[start.cur] + nxt.time;

            if (distance < dis[nxt.cur]) {
                dis[nxt.cur] = distance;
                q.push({nxt.cur, dis[nxt.cur]});
            }
        }
    }
    return dis[D];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N, M, X;
    cin >> N >> M >> X;
    node.resize(N + 2);

    int a, b, c;
    while (M--) {
        cin >> a >> b >> c;
        node[a].push_back({b, c});
    }

    int res = 0;
    for (int I = 1; I <= N; I++) res = max(res, search(I, X, N) + search(X, I, N));
    cout << res;
    return 0;
}