#include <cstdio>
#include <queue>
using namespace std;

#define scale 1001
#define X first
#define Y second
#define position pair<int, int>

int tomato[scale][scale];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;

int main(void) {
    int value, result = -2;
    scanf("%d%d", &M, &N);
    queue<position> data;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            scanf("%d", &tomato[x][y]);
            if (tomato[x][y] == 1) {
                data.push({x, y});
            }
        }
    }

    while(!data.empty()) {
        position cur = data.front();
        data.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (tomato[nx][ny] != 0) continue;
            tomato[nx][ny] = tomato[cur.X][cur.Y] + 1;
            data.push({nx, ny});
        }
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (tomato[x][y] > result) result = tomato[x][y];
            if (tomato[x][y] == 0) {
                printf("-1");
                return 0;
            }
        }
    }
    if (result > 1) printf("%d", result - 1);
    else printf("0");
    return 0;
}