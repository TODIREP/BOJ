#include <iostream>
using namespace std;

bool valid(int x, int y) {
    return (x < 0 || x >= 19 || y >= 19);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int map[21][21], count, winner = 0, wx, wy;
    int dx[4] = {1, 1, 0, -1};
    int dy[4] = {1, 0, 1, 1};

    for (int x = 0; x < 19; x++) {
        for (int y = 0; y < 19; y++) {
            cin >> map[x][y];
        }
    }

    for (int x = 0; x < 19; x++) {
        for (int y = 0; y < 19; y++) {
            if (map[x][y] == 0) continue;
            for (int dir = 0; dir < 4; dir++) {
                count = 1;
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (valid(nx, ny)) continue;
                while (map[nx][ny] == map[x][y]) {
                    count++;
                    if (valid(nx, ny)) break;
                    nx += dx[dir];
                    ny += dy[dir];
                }

                if (count == 5) {
                    nx = x - dx[dir];
                    ny = y - dy[dir];
                    if (!valid(nx, ny) && map[x][y] == map[nx][ny]) continue;
                    cout << map[x][y] << "\n" << x + 1 << " " << y + 1;
                    return 0;
                }
            }
        }
    }
    cout << "0";
    return 0;
}