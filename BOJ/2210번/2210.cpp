#include <iostream>
#include <stack>
using namespace std;

#define MAX_SIZE 1000001
int list[MAX_SIZE];
int map[6][6];
int N = 5;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef struct {
    int X;
    int Y;
    int len;
    int number;
} num;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<num> stk;
    int answer = 0;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cin >> map[x][y];
        }
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            stk.push({x, y, 1, 1 * map[x][y]});
            while (!stk.empty()) {
                auto cur = stk.top();
                stk.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    int nlen = cur.len * 10;
                    int nnumber = cur.number + map[nx][ny] * nlen;

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (nlen == 100000) {
                        if (!list[nnumber]) {
                            list[nnumber] = 1;
                            answer++;
                        }
                        continue;
                    }
                    stk.push({nx, ny, nlen, nnumber});
                }
            }
        }
    }
    cout << answer;
    return 0;
}