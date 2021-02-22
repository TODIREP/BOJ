#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, M, T;
    cin >> N >> M >> T;

    vector<vector<int> > castle(N);

    for (int x = 0; x < N; x++) {
        castle[x].resize(M);
        for (int y = 0; y < M; y++) {
            cin >> castle[x][y];
            if (castle[x][y] > 0) castle[x][y] *= -1;
            else castle[x][y] = 100000;
        }
    }

    int gx = -1, gy = -1;
    queue<pair<int, int> > q;
    castle[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (castle[nx][ny] == -1) continue;
            if (castle[nx][ny] >= 0 && castle[nx][ny] <= castle[cur.first][cur.second] + 1) continue;
            if (castle[nx][ny] == -2) {
                gx = nx;
                gy = ny;
            }

            castle[nx][ny] = castle[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    
    int dis = 100000;
    if (gx >= 0 && gy >= 0) dis = castle[gx][gy] + abs(N - 1 - gx) + abs(M - 1 - gy);
    int res = min(castle[N - 1][M - 1], dis);

    if (res <= T) cout << res;
    else cout << "Fail";
    return 0;
}