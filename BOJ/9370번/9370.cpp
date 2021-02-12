#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int INF = 3000000;
struct link {
    int start;
    int time;
    bool operator<(const link &a) const { return time > a.time; }
};
int search(vector<vector<link > > &target, vector<int> &res, int sp, int tp, int len) {
    vector<int> dis;
    dis.assign(len + 2, INF);

    priority_queue<link > q;
    dis[sp] = 0;
    q.push({sp, dis[sp]});

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();

        if (cur.time != dis[cur.start]) continue;

        for (auto nxt: target[cur.start]) {
            int distance = dis[cur.start] + nxt.time;

            if (distance < dis[nxt.start]) {
                dis[nxt.start] = distance;
                q.push({nxt.start, dis[nxt.start]});
            }
        }
    }

    for (int i = 1; i <= len; i++) res[i] = dis[i];
    return dis[tp];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int P, N, M, T, S, G, H, A, B, D;
    cin >> P;

    while (P--) {
        cin >> N >> M >> T >> S >> G >> H;
        vector<vector<link > > node(N + 2);

        while (M--) {
            cin >> A >> B >> D;
            node[A].push_back({B, D});
            node[B].push_back({A, D});
        }

        vector<int> HG(N + 2), GH(N + 2), MD(N + 2), SD(N + 2);
        int h_to_g = search(node, HG, S, H, N) + search(node, HG, H, G, N);
        int g_to_t = search(node, HG, G, N, N);
        for (int i = 1; i <= N; i++) HG[i] += h_to_g;

        int g_to_h = search(node, GH, S, G, N) + search(node, GH, G, H, N);
        int h_to_t = search(node, GH, H, N, N);
        for (int i = 1; i <= N; i++) GH[i] += g_to_h;

        for (int i = 1; i <= N; i++) MD[i] = min(HG[i], GH[i]);
        int s_to_t = search(node, SD, S, N, N);

        vector<int> target(T);
        for (int i = 0; i < T; i++) cin >> target[i];
        sort(target.begin(), target.end());

        for (int i = 0; i < T; i++) if (MD[target[i]] <= SD[target[i]]) cout << target[i] << " ";
        cout << "\n";
    }
    return 0;
}