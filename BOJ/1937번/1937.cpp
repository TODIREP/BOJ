#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int N, tree[501][501], res[501][501], result = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool rng(int x, int y) { return (x < 0 || x >= N || y < 0 || y >= N); }

int search(int x, int y) {
    int result = 1;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (rng(nx, ny) || tree[nx][ny] <= tree[x][y]) continue;
        int next = res[nx][ny] > 0 ? res[nx][ny] : search(nx, ny);
        result = max(result, next + 1);
    }
    return res[x][y] = result;
}

int main(void) {
    fastio
    cin >> N;
    for (int x = 0; x < N; x++) for (int y = 0; y < N; y++) cin >> tree[x][y];
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (res[x][y] == 0) result = max(result, search(x, y));
            else result = max(result, res[x][y]);
        }
    }
    cout << result;
    return 0;
}