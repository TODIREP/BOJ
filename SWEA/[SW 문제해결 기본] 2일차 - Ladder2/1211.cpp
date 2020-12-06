#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char** argv) {
    int T;
    int map[101][101];
    for (int test_case = 0; test_case < 10; test_case++) {
        int count, min = 2000, minX;
        cin >> T;
        queue<pair<int, int>> start;

        for (int x = 0; x < 100; x++) {
            for (int y = 0; y < 100; y++) {
                cin >> map[x][y];
                if (x == 0 && map[x][y] == 1) {
                    start.push({x, y});
                }
            }
        }

        int dy[2] = {-1, 1};

        while (!start.empty()) {
            count = 0;
            auto cur = start.front();
            start.pop();
            int startY = cur.second;

            while (cur.first != 99) {
                for (int dir = 0; dir < 2; dir++) {
                    int ny = cur.second + dy[dir];
                    if (ny < 0 || ny >= 100) continue;
                    if (map[cur.first][ny] == 0) continue;
                    while (map[cur.first][ny] != 0) {
                        ny += dy[dir];
                        count++;
                    }
                    cur.second = ny - dy[dir];
                    break;
                }
                cur.first++;
                count++;
            }
            if (count <= min) {
                min = count;
                minX = startY;
            }
        }

        cout << "#" << T << " " << minX << "\n";
    }
    return 0;
}