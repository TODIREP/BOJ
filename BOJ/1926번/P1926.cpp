#include <cstdio>
#include <queue>
using namespace std;

#define X first
#define Y second
#define position pair<int, int>
#define max_size 502
int n, m;
int board[max_size][max_size];
bool visit[max_size][max_size];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    int count = 0, size = 0, max = -1;
    queue<position> data;
    scanf("%d%d", &n, &m);
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            scanf("%d", &board[x][y]);
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (board[x][y] == 1 && !visit[x][y]) {
                size = 0;
                count++;
                visit[x][y] = 1;
                data.push({x, y});
                while (!data.empty()) {
                    position current = data.front();
                    data.pop();
                    size++;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = current.X + dx[dir];
                        int ny = current.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (board[nx][ny] != 1 || visit[nx][ny]) continue;
                        visit[nx][ny] = 1;
                        data.push({nx, ny});
                    }
                }
                if (size >= max) max = size;
            }
        }
    }
    if (count == 0) {
        printf("0\n0");
    } else printf("%d\n%d", count, max);
    return 0;
}