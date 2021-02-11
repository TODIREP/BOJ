#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 16000;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct mov {
    int X;
    int Y;
    int coin;
    bool operator<(const mov &a) const { return coin > a.coin; }
};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N, cases = 1;
    while (cases) {
        cin >> N;
        if (N == 0) return 0;
        vector<vector<int > > cave(N + 1), dis(N + 1);

        for (int x = 0; x < N; x++) {
            cave[x].resize(N + 1);
            dis[x].assign(N + 1, INF);
            for (int y = 0; y < N; y++) cin >> cave[x][y];
        }

        priority_queue<mov > q;
        dis[0][0] = cave[0][0];
        q.push({0, 0, dis[0][0]});

        while (!q.empty()) {
            auto cur = q.top();
            q.pop();

            if (cur.coin != dis[cur.X][cur.Y]) continue;

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                int nc = cur.coin + cave[nx][ny];

                if (nc < dis[nx][ny]) {
                    dis[nx][ny] = nc;
                    q.push({nx, ny, dis[nx][ny]});
                }
            }
        }
        cout << "Problem " << cases++ << ": " << dis[N - 1][N - 1] << "\n";
    }
}