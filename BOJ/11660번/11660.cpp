#include <iostream>
using namespace std;
#define plus(a, b) (a + b)
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int map[1025][1025], sum[1025][1025];
int main(void) {
    fastio();
    int N, M;
    cin >> N >> M;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cin >> map[x][y];
            if (x == 0) sum[x][y] = map[x][y];
            else sum[x][y] = sum[x - 1][y] + map[x][y];
        }
    }
    int sx, sy, ex, ey;
    while (M--) {
        cin >> sx >> sy >> ex >> ey;
        int ans = 0;
        for (int end = sy - 1; end <= ey - 1; end++) ans += sum[ex - 1][end];
        if (sx > 1) for (int end = sy - 1; end <= ey - 1; end++) ans -= sum[sx - 2][end];
        cout << ans << "\n";
    }
    return 0;
}