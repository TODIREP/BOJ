#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > ice, melt;
int N, M, dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool rng(int x, int y) { return (x < 0 || x >= N || y < 0 || y >= M); }
int check() {
    int island = 0;
    queue<pair<int, int> > q;
    vector<vector<bool> > vis(N);
    for (int i = 0; i < N; i++) vis[i].assign(M, false);

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (ice[x][y] == 0 || vis[x][y]) continue;
            vis[x][y] = true;
            island++;
            q.push({x, y});

            while (!q.empty()) {
                auto cur = q.front();q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (rng(nx, ny)) continue;
                    if (vis[nx][ny] || ice[nx][ny] == 0) continue;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    return island;
}

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int answer = 0;
    cin >> N >> M;
    ice.resize(N);
    melt.resize(N);

    for (int x = 0; x < N; x++) {
        ice[x].resize(M);
        melt[x].assign(M, 0);
        for (int y = 0; y < M; y++) {
            cin >> ice[x][y];
        }
    }

    for (int time = 0;; time++) {
        if (check() >= 2) {
            answer = time;
            break;
        }
        bool valid = false;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                if (ice[x][y] == 0) continue;
                valid = true;
                int cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (rng(nx, ny)) continue;
                    if (ice[nx][ny] > 0) continue;   
                    cnt++;
                }
                melt[x][y] = cnt;
            }
        }
        if (!valid) break;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                ice[x][y] -= melt[x][y];
                if (ice[x][y] < 0) ice[x][y] = 0;
                melt[x][y] = 0;
            }
        }
    }
    cout << answer;
    return 0;
}