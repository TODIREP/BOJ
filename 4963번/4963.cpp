#include <cstdio>
#include <queue>
using namespace std;

#define X first
#define Y second
#define position pair<int, int>

int map[52][52];
int w, h;
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(void) {
    while (true) {
        int answer = 0;
        queue<position> data;
        scanf("%d%d", &w, &h);
        if (!w && !h) return 0;
        for (int x = 0; x < h; x++) {
            for (int y = 0; y < w; y++) {
                scanf("%d", &map[x][y]);
            }
        }
        for (int x = 0; x < h; x++) {
            for (int y = 0; y < w; y++) {
                if (map[x][y] == 1) {
                    map[x][y] = 0;
                    answer++;
                    data.push({x, y});
                    while(!data.empty()) {
                        position cur = data.front();
                        data.pop();
                        for (int dir = 0; dir < 8; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                            if (map[nx][ny] == 0) continue;
                            map[nx][ny] = 0;
                            data.push({nx, ny});
                        }
                    }
                }
            }
        }
        printf("%d\n", answer);
    }
}