#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N, M, X, Y, K;
    cin >> N >> M;

    vector<int> indegree(N + 2);
    vector<vector<pair<int, int> > > node(N + 2);
    vector<vector<int> > parts(N + 2);

    for (int i = 1; i <= N; i++) parts[i].assign(N + 2, 0);

    while (M--) {
        cin >> X >> Y >> K;
        node[Y].push_back({X, K});
        indegree[X]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            parts[i][i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto nxt: node[cur]) {
            for (int i = 1; i <= N; i++) parts[nxt.first][i] += parts[cur][i] * nxt.second;
            if (--indegree[nxt.first] == 0) q.push(nxt.first);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (parts[N][i] == 0) continue;
        cout << i << " " << parts[N][i] << "\n";
    }
    return 0;
}