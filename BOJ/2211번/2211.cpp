#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct link {
    int start, time;
    bool operator<(const link &a) const {
        return time > a.time;
    }
};

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> dis(N + 1, 1000000), pre(N + 1);
    vector<vector<link> > node(N + 1);

    int A, B, C;
    for (int i = 0; i < K; i++) {
        cin >> A >> B >> C;
        node[A].push_back({B, C});
        node[B].push_back({A, C});
    }

    priority_queue<link> q;
    dis[1] = 0;
    q.push({1, dis[1]});
    
    while (!q.empty()) {
        auto cur = q.top();q.pop();

        if (dis[cur.start] != cur.time) continue;

        for (auto nxt: node[cur.start]) {
            int distance = dis[cur.start] + nxt.time;

            if (distance < dis[nxt.start]) {
                dis[nxt.start] = distance;
                pre[nxt.start] = cur.start;
                q.push({nxt.start, dis[nxt.start]});
            }
        }
    }
    
    vector<pair<int, int> > res;
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (pre[i] == 0) continue;
        res.push_back({i, pre[i]});
        count++;
    }

    cout << count << "\n";
    for (auto result: res) {
        cout << result.first << " " << result.second << "\n";
    }
    return 0;
}