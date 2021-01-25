#include <iostream>
#include <cmath>
using namespace std;
#define lint long long
#define rx first
#define ry second
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

double wind[9] = {0.01, 0.01, 0.07, 0.07, 0.1, 0.1, 0.02, 0.02, 0.05};
pair<int, int> mov1[9] = {{-1, 0}, {1, 0}, {-1, -1}, {1, -1}, {-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {0, -3}};
pair<int, int> mov2[9] = {{0, -1}, {0, 1}, {1, 1}, {1, -1}, {2, 1}, {2, -1}, {1, 2}, {1, -2}, {3, 0}};
pair<int, int> mov3[9] = {{-1, 0}, {1, 0}, {-1, 1}, {1, 1}, {-1, 2}, {1, 2}, {-2, 1}, {2, 1}, {0, 3}};
pair<int, int> mov4[9] = {{0, -1}, {0, 1}, {-1, 1}, {-1, -1}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {-3, 0}};
pair<int, int>* getMov(int index) {
    if (index == 0) return mov1;
    if (index == 1) return mov2;
    if (index == 2) return mov3;
    return mov4;
}
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
lint N, map[501][501], temp[501][501];
bool vis[501][501];

bool rng(int x, int y) { return (x < 0 || x >= N || y < 0 || y >= N);}
int main(void) {
    fastio();
    lint res = 0;
    cin >> N;
    for (int x = 0; x < N; x++) for (int y = 0; y < N; y++) cin >> map[x][y];
    int x = N / 2;
    int y = N / 2;
    int dir = 0;
    auto direction = getMov(dir);
    temp[x][y] = 1;

    while (true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        vis[x][y] = true;
        if (x == 0 && y == 0) break;

        int sum = 0;
        for (int index = 0; index < 9; index++) {
            int nrx = x + direction[index].rx;
            int nry = y + direction[index].ry;
            lint sand = floor(map[nx][ny] * wind[index]);
            sum += sand;
            if (rng(nrx, nry)) res += sand;
            else map[nrx][nry] += sand;
        }
        int tx = nx + dx[dir];
        int ty = ny + dy[dir];
        if (rng(tx, ty)) res += map[nx][ny] - sum;
        else map[tx][ty] += map[nx][ny] - sum;

        int ndir = (dir + 1) % 4;
        temp[nx][ny] = temp[x][y] + 1;
        if (!vis[nx + dx[ndir]][ny + dy[ndir]]) {
            dir = ndir;
            direction = getMov(dir);
        }
        x = nx;
        y = ny;
    }
    cout << res;
    return 0;
}