#include <iostream>
using namespace std;
#define NUM long long

NUM miro[1001][1001], count[1001][1001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) cin >> miro[x][y];
    }

    count[0][0] = miro[0][0];
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (y + 1 < M && x + 1 < N) count[x + 1][y + 1] = max(count[x + 1][y + 1], count[x][y] + miro[x + 1][y + 1]);
            if (y + 1 < M) count[x][y + 1] = max(count[x][y + 1], count[x][y] + miro[x][y + 1]);
            if (x + 1 < N) count[x + 1][y] = max(count[x + 1][y], count[x][y] + miro[x + 1][y]);
        }
    }
    cout << count[N - 1][M - 1];
    return 0;
}