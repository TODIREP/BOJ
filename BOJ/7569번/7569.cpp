#include <cstdio>
#include <queue>
using namespace std;

#define scale 101
#define position pair<int, int>
int tomato[scale][scale][scale];
int n, m, h;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(void) {
    int result = -1;
    scanf("%d%d%d", &m, &n, &h);
    queue<pair<position, int>> data;
    for (int z = 0; z < h; z++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                scanf("%d", &tomato[x][y][z]);
                if (tomato[x][y][z] == 1) {
                    data.push({{x, y}, z});
                }
            }
        }
    }

    while (!data.empty()) {
        pair<position, int> current = data.front();
        data.pop();
        
        for (int dir = 0; dir < 6; dir++) {
            int nx = current.first.first + dx[dir];
            int ny = current.first.second + dy[dir];
            int nz = current.second + dz[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (tomato[nx][ny][nz] == -1 || tomato[nx][ny][nz] != 0) continue;

            tomato[nx][ny][nz] = tomato[current.first.first][current.first.second][current.second] + 1;
            data.push({{nx, ny}, nz});
        }
    }

    for (int z = 0; z < h; z++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (tomato[x][y][z] == 0) {
                    printf("-1");
                    return 0;
                }
                if (tomato[x][y][z] > result) result = tomato[x][y][z];
            }
        }
    }
    printf("%d", result - 1);
    return 0;
}