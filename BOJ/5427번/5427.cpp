#include <cstdio>
#include <queue>
using namespace std;

#define scale 1001
#define pos pair<int, int>
int map[scale][scale];
int fire[scale][scale];
int N, w, h;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    char input[1001];
    scanf("%d", &N);

    while(N--) {
        int result = 1005;
        scanf("%d%d", &h, &w);
        queue<pos> m;
        queue<pos> f;
        for (int x = 0; x < w; x++) {
            scanf("%s", input);
            for (int y = 0; y < h; y++) {
                if (input[y] == '#') {
                    map[x][y] = -1;
                    fire[x][y] = -1;
                }
                if (input[y] == '.') {
                    map[x][y] = 0;
                    fire[x][y] = 0;
                }
                if (input[y] == '*') {
                    fire[x][y] = 1;
                    map[x][y] = -1;
                    f.push({x, y});
                }
                if (input[y] == '@') {
                    map[x][y] = 1;
                    m.push({x, y});
                }
            }
        }
        while (!f.empty()) {
            pos current = f.front();
            f.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = current.first + dx[dir];
                int ny = current.second + dy[dir];

                if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                if (fire[nx][ny] != 0 || fire[nx][ny] == -1) continue;

                fire[nx][ny] = fire[current.first][current.second] + 1;
                f.push({nx, ny});
            }
        }
        while (!m.empty()) {
            pos current = m.front();
            m.pop();
            if (current.first == 0 || current.first == w - 1 || current.second == 0 || current.second == h - 1) {
                result = map[current.first][current.second];
                break;
            }
            for (int dir = 0; dir < 4; dir++) {
                int nx = current.first + dx[dir];
                int ny = current.second + dy[dir];

                if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                if (map[nx][ny] != 0 || map[nx][ny] == -1) continue;
                map[nx][ny] = map[current.first][current.second] + 1;
                if (map[nx][ny] >= fire[nx][ny] && fire[nx][ny] > 0) {
                    map[nx][ny] = -1;
                    continue;
                }
                m.push({nx, ny});
            }
        }
        if (result == 1005) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", result);
        }
    }
    return 0;
}