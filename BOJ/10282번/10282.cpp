#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 20000000;
struct link {
    int start, time;
    bool operator<(const link &a) const { return time > a.time; }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, D, C;
        cin >> N >> D >> C;

        vector<int> dis(N + 2, INF);
        vector<vector<link > > node(N + 2);

        int A, B, S;
        while (D--) {
            cin >> A >> B >> S;
            node[B].push_back({A, S});
        }

        priority_queue<link > q;
        dis[C] = 0;
        q.push({C, dis[C]});

        while (!q.empty()) {
            auto cur = q.top();
            q.pop();

            if (cur.time != dis[cur.start]) continue;

            for (auto nxt : node[cur.start]) {
                int distance = dis[cur.start] + nxt.time;

                if (distance < dis[nxt.start]) {
                    dis[nxt.start] = distance;
                    q.push({nxt.start, dis[nxt.start]});
                }
            }
        }
        int res_count = 0, res_time = 0;
        for (int i = 1; i <= N; i++) {
            if (dis[i] >= INF) continue;
            res_count++;
            res_time = max(res_time, dis[i]);
        }
        cout << res_count << " " << res_time << "\n";
    }
    return 0;
}