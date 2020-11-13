#include <cstdio>
#include <queue>
using namespace std;

#define scale 101
#define X first
#define Y second
#define position pair<int, int>

int map[scale][scale];
bool visit[scale][scale];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N;

int main(void) {
    int max = -1, count = 0, result = -1;
    scanf("%d", &N);

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            scanf("%d", &map[x][y]);
            if (map[x][y] > max) max = map[x][y];
        }
    }

    for (int index = 0; index <= max; index++) {
        queue<position> data;
        queue<position> reset;
        count = 0;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (map[x][y] > index && visit[x][y] == 0) {
                    data.push({x, y});
                    reset.push({x, y});
                    visit[x][y] = 1;
                    while(!data.empty()) {
                        position current = data.front();
                        data.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            int nx = current.X + dx[dir];
                            int ny = current.Y + dy[dir];

                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if (map[nx][ny] <= index) {
                                reset.push({nx, ny});
                                continue;
                            }
                            if (visit[nx][ny]) continue;

                            visit[nx][ny] = 1;
                            data.push({nx, ny});
                        }
                    }
                    count++;
                } else {
                    reset.push({x, y});
                }
            }
        }
        while (!reset.empty()) {
            position erase = reset.front();
            reset.pop();
            visit[erase.X][erase.Y] = 0;
        }
        if (count >= result) result = count;
    }
    printf("%d", result);
    return 0;
}