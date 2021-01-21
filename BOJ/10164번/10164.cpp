#include <iostream>
using namespace std;

int map[16][16], count[16][16];
int search(int sx, int sy, int tx, int ty) {
    count[sx][sy] = 1;
    for (int x = sx; x <= tx; x++) {
        for (int y = sy; y <= ty; y++) {
            if (y + 1 <= ty) count[x][y + 1] += count[x][y];
            if (x + 1 <= tx) count[x + 1][y] += count[x][y];
        }
    }
    return count[tx][ty];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K, num = 1;
    cin >> N >> M >> K;
    for (int x = 0; x < N; x++) for (int y = 0; y < M; y++) map[x][y] = num++;
    if (K != 0) {
        int x = (K - 1) / M;
        int y = (K - 1) % M;
        cout << search(0, 0, x, y) * search(x, y, N - 1, M - 1);
    }
    else cout << search(0, 0, N - 1, M - 1);
    return 0;
}