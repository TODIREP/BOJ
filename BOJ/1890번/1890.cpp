#include <iostream>
using namespace std;

long long map[101][101], count[101][101], N;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) cin >> map[x][y];
    }

    count[0][0] = 1;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (count[x][y] == 0 || map[x][y] == 0) continue;
            if (x + map[x][y] < N) count[x + map[x][y]][y] += count[x][y];
            if (y + map[x][y] < N) count[x][y + map[x][y]] += count[x][y];
        }
    }
    cout << count[N - 1][N - 1];
    return 0;
}