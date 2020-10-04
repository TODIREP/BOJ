#include <cstdio>
#include <queue>
using namespace std;

#define X first
#define Y second
#define position pair<int, int>
#define scale 101
int board[scale][scale];
bool visit[scale][scale];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int main(void) {
    char input[102];
    queue<position> data;
    scanf("%d%d", &n, &m);
    for (int x = 0; x < n; x++) {
        scanf("%s", input);
        for (int index = 0; input[index] != '\0'; index++) {
            board[x][index] = input[index] - 48;
        }
    }
    data.push({0, 0});
    visit[0][0] = 1;
    while (!data.empty()) {
        position current = data.front();
        data.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = current.X + dx[dir];
            int ny = current.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visit[nx][ny] || board[nx][ny] == 0) continue;
            visit[nx][ny] = 1;
            board[nx][ny] = board[current.X][current.Y] + 1;
            data.push({nx, ny});
        }
    }
    printf("%d", board[n - 1][m - 1]);
    return 0;
}