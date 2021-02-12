#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T, N, K, X, Y, W;
    cin >> T;

    while (T--) {
        cin >> N >> K;
        vector<int> indegree(N + 2), times(N + 2), res(N + 2);
        vector<vector<int> > node(N + 2);

        for (int i = 1; i <= N; i++) {
            cin >> times[i];
            res[i] = times[i];
        }

        while (K--) {
            cin >> X >> Y;
            node[X].push_back(Y);
            indegree[Y]++;
        }

        queue<int> q;
        for (int i = 1; i <= N; i++) if (indegree[i] == 0) q.push(i);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int nxt: node[cur]) {
                res[nxt] = max(res[nxt], res[cur] + times[nxt]);
                if (--indegree[nxt] == 0) q.push(nxt);
            }
        }
        cin >> W;
        cout << res[W] << "\n";
    }
    return 0;
}