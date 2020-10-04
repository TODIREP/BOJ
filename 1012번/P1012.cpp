#include <cstdio>
#include <queue>
using namespace std;

#define scale 52
#define X first
#define Y second
#define position pair<int, int>

int board[scale][scale];
bool visit[scale][scale];
int n, m, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    int cases, x, y, count;
    scanf("%d", &cases);
    for (int times = 0; times < cases; times++) {
        scanf("%d%d%d", &n, &m, &k);
        for (int p = 0; p < n; p++) {
            for (int q = 0; q < m; q++) {
                board[p][q] = 0;
                visit[p][q] = 0;
            }
        }
        for (int p = 0; p < k; p++) {
            scanf("%d%d", &x, &y);
            board[x][y] = 1;
        }

        count = 0;
        queue<position> data;

        for (int p = 0; p < n; p++) {
            for (int q = 0; q < m; q++) {
                if (board[p][q] == 1 && !visit[p][q]) {
                    count++;
                    visit[p][q] = 1;
                    data.push({p, q});

                    while(!data.empty()) {
                        position current = data.front();
                        data.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            int nx = current.X + dx[dir];
                            int ny = current.Y + dy[dir];

                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if (visit[nx][ny] || board[nx][ny] != 1) continue;

                            visit[nx][ny] = 1;
                            data.push({nx, ny});
                        }
                    }
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}