#include <cstdio>
#include <queue>
using namespace std;

#define scale 26
#define position pair<int, int>
#define X first
#define Y second
#define maximum scale * scale + 1
int sort_arr[maximum];
int board[scale][scale];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N;

int main(void) {
    int result = 0, count;
    char input[26];
    queue<position> data;
    scanf("%d", &N);
    for (int test = 0; test < N; test++) {
        scanf("%s", input);
        for (int index = 0; input[index] != '\0'; index++) {
            board[test][index] = input[index] - 48;
        }
    }
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (board[x][y] == 1) {
                data.push({x, y});
                board[x][y] = 0;
                count = 0;
                
                while (!data.empty()) {
                    position current = data.front();
                    data.pop();
                    count++;

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = current.X + dx[dir];
                        int ny = current.Y + dy[dir];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (board[nx][ny] == 0) continue;
                        board[nx][ny] = 0;
                        data.push({nx, ny});
                    }
                }
                result++;
                sort_arr[count]++;
            }
        }
    }
    printf("%d\n", result);
    for (int index = 0; index < maximum; index++) {
        if (sort_arr[index] != 0) {
            for (int cases = 0; cases < sort_arr[index]; cases++) {
                printf("%d\n", index);
            }
        }
    }
    return 0;
}