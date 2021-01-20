#include <iostream>
using namespace std;

int N, map[17][17], count[17][17][3];
void search(int x, int y) {
    if (y >= N) {
        x++;
        y = 0;
    }
    if (x >= N) return;
    if (map[x][y] == 1) return search(x, y + 1);
    if (x == 0) {
        if (map[x][y - 1] != 1) count[x][y][0] = count[x][y - 1][0];
    } else if (y == 0) {
        if (map[x - 1][y] != 1) count[x][y][1] = count[x - 1][y][1];
    } else {
        if (map[x - 1][y] != 1 && map[x][y - 1] != 1 && map[x][y - 1] != 1) count[x][y][2] = count[x - 1][y - 1][2] + count[x - 1][y - 1][1] + count[x - 1][y - 1][0];
        if (map[x - 1][y] != 1) count[x][y][1] = count[x - 1][y][1] + count[x - 1][y][2];
        if (map[x][y - 1] != 1) count[x][y][0] = count[x][y - 1][0] + count[x][y - 1][2];
    }
    return search(x, y + 1);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cin >> map[x][y];
        }
    }
    count[0][1][0] = 1;
    search(0, 2);
    int result = 0;
    for (int x = 0; x < 3; x++) result += count[N - 1][N - 1][x];
    cout << result;
    return 0;
}