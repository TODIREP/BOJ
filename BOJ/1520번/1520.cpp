#include <iostream>
using namespace std;

int N, M;
int map[501][501], mov[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) { return (x < 0 || x >= N || y < 0 || y >= M); }
int search(int x, int y) {
    int sum = 0;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (valid(nx, ny) || map[nx][ny] <= map[x][y]) continue;
        sum += (mov[nx][ny] != -1) ? mov[nx][ny] : search(nx, ny);
    }
    mov[x][y] = sum;
    return mov[x][y];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            cin >> map[x][y];
            mov[x][y] = -1;
        }
    }
    mov[0][0] = 1;
    search(N - 1, M - 1);
    cout << mov[N - 1][M - 1];
    return 0;
}