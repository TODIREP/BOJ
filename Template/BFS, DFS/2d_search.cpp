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
/*
예제입력
5
1 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0
0 0 0 0 1
*/
    scanf("%d", &N);
    queue<position> data;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            scanf("%d", &map[x][y]);

            if (map[x][y] == 1) {
                data.push({x, y});
            }
        }
    }
 
    while(!data.empty()) {
        position current = data.front();
        data.pop();
        visit[current.X][current.Y] = 1;

        for (int dir = 0; dir < 4; dir++) {
            int nx = current.X + dx[dir];
            int ny = current.Y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visit[nx][ny]) continue;

            visit[nx][ny] = 1;
            map[nx][ny] = map[current.X][current.Y] + 1;
            data.push({nx, ny});
        }
    }
/*
예제출력
1 2 3 4 5
2 3 2 3 4
3 2 1 2 3
4 3 2 3 2
5 4 3 2 1
*/
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            printf("%d ", map[x][y]);
        } printf("\n");
    }
    return 0;
}