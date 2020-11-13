#include <iostream>
#include <queue>
using namespace std;

int map[31][31][31];
int L, R, C;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(void) {
    char floors[32], target_x, target_y, target_z;
    while (true) {
        int result = -1;
        queue<pair<pair<int, int>, int>> data;
        cin >> L >> R >> C;
        if (L == 0) break;
        
        for (int x = 0; x < L; x++) {
            for (int y = 0; y < R; y++) {
                cin >> floors;
                for (int z = 0; z < C; z++) {
                    if (floors[z] == 'S') {
                        map[x][y][z] = 1;
                        data.push({{x, y}, z});
                    }
                    if (floors[z] == '.') {
                        map[x][y][z] = 0;
                    }
                    if (floors[z] == '#') {
                        map[x][y][z] = -1;
                    }
                    if (floors[z] == 'E') {
                        map[x][y][z] = 0;
                        target_x = x;
                        target_y = y;
                        target_z = z;
                    }
                }
            }
        }

        while(!data.empty()) {
            int x, y, z;
            auto current = data.front();
            data.pop();
            x = current.first.first;
            y = current.first.second;
            z = current.second;

            if (x == target_x && y == target_y && z == target_z) {
                result = map[x][y][z] - 1;
                break;
            }

            for (int dir = 0; dir < 6; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                int nz = z + dz[dir];

                if (nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C) continue;
                if (map[nx][ny][nz] != 0 || map[nx][ny][nz] == -1) continue;

                map[nx][ny][nz] = map[x][y][z] + 1;
                data.push({{nx, ny}, nz});
            }
        }
        if (result != -1) {
            cout << "Escaped in " << result << " minute(s).\n";
        } else {
            cout << "Trapped!\n";
        }
    }
    return 0;
}