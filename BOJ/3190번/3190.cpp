#include <iostream>
#include <deque>
using namespace std;
#define pos pair<int, int>
#define rx first
#define ry second
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N, map[101][101];
bool rng(int x, int y) { return (x < 0 || x >= N || y < 0 || y >= N); }
int main(void) {
    fastio();
    deque<pos> direction, snake;
    int K, L;
    int kx, ky;
    char idir[2];
    cin >> N >> K;
    for (int index = 0; index < K; index++) {
        cin >> kx >> ky;
        map[kx - 1][ky - 1] = 2;
    }

    cin >> L;
    for (int index = 0; index < L; index++) {
        cin >> kx >> idir;
        if (idir[0] == 'D') direction.push_back({kx, 1});
        else direction.push_back({kx, -1});
    }

    int times = 0, dir = 0;
    int cx = 0, cy = 0;
    snake.push_back({cx, cy});
    while (true) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        times++;
        if (rng(nx, ny) || map[nx][ny] == 1) break;

        snake.push_back({nx, ny});
        if (map[nx][ny] == 0) {
            auto before = snake.front();
            map[before.rx][before.ry] = 0;
            snake.pop_front();
        }
        map[nx][ny] = 1;

        if (direction.front().rx == times) {
            dir += direction.front().ry;
            if (dir > 3) dir = 0;
            if (dir < 0) dir = 3;
            direction.pop_front();
        }
        cx = nx;
        cy = ny;
    }
    cout << times;
    return 0;
}