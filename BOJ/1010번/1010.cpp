#include <iostream>
using namespace std;

int bridge[30][30];
int build(int n, int m) {
    if (n == m || n == 0) {
        bridge[n][m] = 1;
        return bridge[n][m];
    }
    for (int y = m - 1; y >= n - 1; y--) {
        if (bridge[n - 1][y] != 0) bridge[n][m] += bridge[n - 1][y];
        else bridge[n][m] += build(n - 1, y);
    }
    return bridge[n][m];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, N, M;
    cin >> T;
    for (int index = 0; index < T; index++) {
        cin >> N >> M;
        cout << build(N, M) << "\n";
    }
    return 0;
}