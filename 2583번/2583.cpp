#include <cstdio>
#include <queue>
using namespace std;

#define scale 101
#define position pair<int, int>
#define X first
#define Y second
int board[scale][scale];
int arr[10002];
int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    int K, x, y, a, b, count, result = 0;
    scanf("%d%d%d", &M, &N, &K);
    queue<position> data;
    for (int test_case = 0; test_case < K; test_case++) {
        scanf("%d%d%d%d", &x, &y, &a, &b);
        for (int index = y; index < b; index++) {
            for (int index2 = x; index2 < a; index2++) {
                board[index2][index]++;
            }
        }
    }
    for (y = 0; y < M; y++) {
        for (x = 0; x < N; x++) {
            if (board[x][y] == 0) {
                data.push({x, y});
                board[x][y] = -1;
                count = 0;
                while(!data.empty()) {
                    position current = data.front();
                    data.pop();
                    count++;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = current.X + dx[dir];
                        int ny = current.Y + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (board[nx][ny] != 0) continue;
                        board[nx][ny] = -1;
                        data.push({nx, ny});
                    }
                }
                result++;
                arr[count]++;
            }
        }
    }
    printf("%d\n", result);
    for (int index = 0; index < 10001; index++) {
        if (arr[index] != 0) {
            for (int counter = 0; counter < arr[index]; counter++) {
                printf("%d ", index);
            }
        }
    }
    return 0;
}