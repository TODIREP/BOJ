#include <cstdio>
#include <queue>
using namespace std;

#define scale 301
#define position pair<int, int>
#define X first
#define Y second

int board[scale][scale];
bool visit[scale][scale];
int N;
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(void) {
    int K, x, y, a, b;
    scanf("%d", &K);
    for (int index = 1; index <= K; index++) {
        scanf("%d%d%d%d%d", &N, &x, &y, &a, &b);

        queue<position> data;
        queue<position> rest;
        data.push({x, y});
        visit[x][y] = 1;
        while (!data.empty()) {
            position current = data.front();
            rest.push(current);
            data.pop();
            if (current.X == a && current.Y == b) {
                while (!data.empty()) {
                    position erase = data.front();
                    rest.push(erase);
                    data.pop();
                }
                break;
            }
            for (int dir = 0; dir < 8; dir++) {
                int nx = current.X + dx[dir];
                int ny = current.Y + dy[dir];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (board[nx][ny] != 0 || visit[nx][ny]) continue;
                visit[nx][ny] = 1;
                board[nx][ny] = board[current.X][current.Y] + 1;
                data.push({nx, ny});
            }
        }
        printf("%d\n", board[a][b]);
        while(!rest.empty()) {
            position target = rest.front();
            rest.pop();
            board[target.X][target.Y] = 0;
            visit[target.X][target.Y] = 0;
        }
    }
    return 0;
}