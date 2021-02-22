#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool rng(int x, int y, int n, int m) {
    return (x < 0 || x >= n || y < 0 || y >= m);
}
int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N = 12, M = 6;
    vector<vector<char> > field(N);

    for (int x = 0; x < N; x++) {
        field[x].resize(M);
        for (int y = 0; y < M; y++) {
            cin >> field[x][y];
        }
    }

    int res = 0;
    while (true) {
        queue<pair<int, int> > q;
        vector<vector<bool> > vis(N);
        vector<pair<int, int> > b;
        for (int x = 0; x < N; x++) vis[x].assign(M, false);

        bool bomb = false;

        for (int x = N - 1; x >= 0; x--) {
            for (int y = 0; y < M; y++) {
                if (field[x][y] == '.' || vis[x][y]) continue;
                vector<pair<int, int> > t;
                int count = 1;
                vis[x][y] = true;
                q.push({x, y});

                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    t.push_back(cur);

                    if (count >= 4 && bomb == false) bomb = true;

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (rng(nx, ny, N, M) || vis[nx][ny]) continue;
                        if (field[nx][ny] == '.' || field[nx][ny] != field[x][y]) continue;

                        vis[nx][ny] = true;
                        count++;
                        q.push({nx, ny});
                    }
                }

                if (count >= 4) {
                    for (auto target: t) b.push_back(target);
                }
            }
        }
        if (!bomb) break;

        res++;
        for (auto bb: b) field[bb.first][bb.second] = '.';

        for (int y = 0; y < M; y++) {
            vector<char> stk;
            for (int x = N - 1; x >= 0; x--) {
                if (field[x][y] == '.') continue;
                stk.push_back(field[x][y]);
                field[x][y] = '.';
            }

            int len = stk.size();
            for (int i = 0; i < len; i++) field[N - 1 - i][y] = stk[i];
        }
    }
    
    cout << res;
    return 0;
}