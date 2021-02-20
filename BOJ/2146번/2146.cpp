#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool rng(int x, int y) { return (x < 0 || x >= N || y < 0 || y >= N); }
int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    queue<pair<int, int> > q;
    vector<vector<int> > bridge(N);

    for (int x = 0; x < N; x++) {
        bridge[x].resize(N);
        for (int y = 0; y < N; y++) {
            cin >> bridge[x][y];
        }
    }

    int check = 0;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (bridge[x][y] <= 0) continue;
            bridge[x][y] = --check;
            q.push({x, y});

            while (!q.empty()) {
                auto cur = q.front();q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (rng(nx, ny) || bridge[nx][ny] <= 0) continue;
                    bridge[nx][ny] = check;

                    q.push({nx, ny});
                }
            }
        }
    }

    int res = 10000000;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (bridge[x][y] >= 0) continue;
            q.push({x, y});

            while (!q.empty()) {
                auto cur = q.front();q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (rng(nx, ny)) continue;
                    if (bridge[nx][ny] == bridge[x][y]) continue;
                    if (bridge[nx][ny] < 0) {
                        res = min(res, bridge[cur.first][cur.second]);
                        continue;
                    }
                    if (bridge[nx][ny] != 0 && bridge[nx][ny] <= bridge[cur.first][cur.second] + 1) continue;

                    if (bridge[cur.first][cur.second] < 0) bridge[nx][ny] = 1;
                    else bridge[nx][ny] = bridge[cur.first][cur.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << res;
    return 0;
}