#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 100000004;
struct course {
    int link;
    int time;
    bool operator<(const course &a) const { return time > a.time; }
};
vector<int> dis, pre;
vector<vector<course > > node;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N, M;
    cin >> N >> M;

    node.resize(N + 2);
    dis.assign(N + 2, INF);
    pre.resize(N + 2);
    
    int a, b, c;
    while (M--) {
        cin >> a >> b >> c;
        node[a].push_back({b, c});
    }

    int S, D;
    cin >> S >> D;

    dis[S] = 0;
    pre[S] = 0;
    priority_queue<course > q;
    q.push({S, dis[S]});
    
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();

        if (cur.time != dis[cur.link]) continue;
        for (auto nxt: node[cur.link]) {
            int distance = dis[cur.link] + nxt.time;
            
            if (distance < dis[nxt.link]) {
                dis[nxt.link] = distance;
                pre[nxt.link] = cur.link;
                q.push({nxt.link, distance});
            }
        }
    }
    cout << dis[D] << "\n";

    int prev = D;
    vector<int> res;
    while (prev != 0) {
        res.push_back(prev);
        prev = pre[prev];
    }
    cout << res.size() << "\n";
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
    return 0;
}