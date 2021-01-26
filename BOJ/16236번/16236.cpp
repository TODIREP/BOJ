#include <iostream>
#include <queue>
using namespace std;
#define pos pair<int, int>
#define rx first
#define ry second
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int N, map[21][21], dis[21][21];
bool vis[21][21];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pos> q;
bool rng(int x, int y) { return (x < 0 || x >= N || y < 0 || y >= N); }
int main(void) {
    fastio();
    int shark = 2, ate = 0, move = 0;
    int sx, sy;
    cin >> N;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cin >> map[x][y];
            if (map[x][y] == 9) {
                dis[x][y] = 0;
                sx = x;
                sy = y;
            }
        }
    }
    q.push({sx, sy});
    vis[sx][sy] = true;
    int min_dis = -1, min_x, min_y;
    while (!q.empty()) {
        pos cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.rx + dx[dir];
            int ny = cur.ry + dy[dir];
            if (rng(nx, ny) || map[nx][ny] > shark || vis[nx][ny]) continue;
            if (dis[nx][ny] != 0 && dis[nx][ny] <= dis[cur.rx][cur.ry]) continue;
            dis[nx][ny] = dis[cur.rx][cur.ry] + 1;
            if (map[nx][ny] > 0 && map[nx][ny] < shark) {
                if (min_dis == -1) {
                    min_dis = dis[nx][ny];
                    min_x = nx;
                    min_y = ny;
                } else {
                    if (min_dis >= dis[nx][ny]) {
                        if (min_dis > dis[nx][ny]) {
                            min_dis = dis[nx][ny];
                            min_x = nx;
                            min_y = ny;
                        } else {
                            if (min_x > nx) {
                                min_x = nx;
                                min_y = ny;
                            } else if (min_x == nx) min_y = min(min_y, ny);
                        }
                    }
                }
            }
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
        if (q.empty()) {
            if (min_dis >= 0) {
                move += min_dis;
                map[sx][sy] = 0;
                sx = min_x;
                sy = min_y;
                min_dis = -1;
                map[sx][sy] = 0;
                q.push({sx, sy});
                ate++;
                if (ate == shark) {
                    shark++;
                    ate = 0;
                }
                for (int x = 0; x < N; x++) {
                    for (int y = 0; y < N; y++) {
                        dis[x][y] = 0;
                        vis[x][y] = false;
                    }
                }
            }
        }
    }
    cout << move;
    return 0;
}