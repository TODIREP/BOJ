#include <iostream>
#include <cmath>
#include <deque>
using namespace std;
#define pos pair<int, int>
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int N, tree[11][11], muck[11][11];
bool rng(int x, int y) { return (x < 0 || x >= N || y < 0 || y >= N); }
int main(void) {
    fastio();
    int M, K;
    deque<int> namu[11][11];
    deque<pair<pos, int>> dead;
    deque<pos> plus;
    cin >> N >> M >> K;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cin >> muck[x][y];
            tree[x][y] = 5;
        }
    }
    int tx, ty, tz;
    for (int index = 0; index < M; index++) {
        cin >> tx >> ty >> tz;
        namu[tx - 1][ty - 1].push_front(tz);
    }
    for (int index = 0; index < K; index++) {
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                int cur, T = namu[x][y].size();
                for (cur = 0; cur < T; cur++) {
                    if (namu[x][y][cur] > tree[x][y]) break;
                    tree[x][y] -= namu[x][y][cur];
                    namu[x][y][cur]++;
                    if (namu[x][y][cur] % 5 == 0) plus.push_front({x, y});
                }
                for (; cur < T; cur++) {
                    dead.push_back({{x, y}, namu[x][y].back()});
                    namu[x][y].pop_back();
                }
            }
        }
        while (!dead.empty()) {
            auto die = dead.front();
            dead.pop_front();
            tree[die.first.first][die.first.second] += floor(die.second / 2);
        }
        while (!plus.empty()) {
            auto center = plus.front();
            plus.pop_front();
            for (int x = center.first - 1; x <= center.first + 1; x++) {
                for (int y = center.second - 1; y <= center.second + 1; y++) {
                    if (rng(x, y) || (x == center.first && y == center.second)) continue;
                    namu[x][y].push_front(1);
                }
            }
        }
        for (int x = 0; x < N; x++) for (int y = 0; y < N; y++) tree[x][y] += muck[x][y];
    }
    int res = 0;
    for (int x = 0; x < N; x++) for (int y = 0; y < N; y++) res += namu[x][y].size();
    cout << res;
    return 0;
}