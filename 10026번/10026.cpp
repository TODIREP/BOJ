#include <cstdio>
#include <queue>
using namespace std;

#define scale 101
#define position pair<int, int>
#define X first
#define Y second
int board[scale][scale];
int board2[scale][scale];
int visit[scale][scale];
int size;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    char input[scale];
    int count = 0, count2 = 0;
    scanf("%d", &size);
    queue<position> data;
    for (int x = 0; x < size; x++) {
        scanf("%s", input);
        for (int y = 0; input[y] != '\0'; y++) {
            board[x][y] = input[y];
            board2[x][y] = input[y] == 'R' ? board2[x][y] = 'G' : input[y];
        }
    }

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (visit[x][y] == 0) {
                data.push({x, y});
                visit[x][y]++;
                count++;
                while (!data.empty()) {
                    position current = data.front();
                    data.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = current.X + dx[dir];
                        int ny = current.Y + dy[dir];

                        if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
                        if (board[nx][ny] != board[current.X][current.Y] || visit[nx][ny] == 1) continue;
                        visit[nx][ny]++;
                        data.push({nx, ny});
                    }
                }
            }
        }
    }
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (visit[x][y] == 1) {
                data.push({x, y});
                visit[x][y]--;
                count2++;
                while (!data.empty()) {
                    position current = data.front();
                    data.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = current.X + dx[dir];
                        int ny = current.Y + dy[dir];

                        if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
                        if (board2[nx][ny] != board2[current.X][current.Y] || visit[nx][ny] == 0) continue;
                        visit[nx][ny]--;
                        data.push({nx, ny});
                    }
                }
            }
        }
    }
    printf("%d %d", count, count2);
    return 0;
}