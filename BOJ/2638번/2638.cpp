#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool rng(int x, int y, int n, int m) {
    return (x < 0 || x >= n || y < 0 || y >= m);
}
int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > cheese(N);

    for (int x = 0; x < N; x++) {
        cheese[x].resize(M);
        for (int y = 0; y < M; y++) {
            cin >> cheese[x][y];
        }
    }
    
    int res = 0;
    while (++res) {
        vector<vector<int> > air(N);
        vector<vector<bool> > melt(N);
        for (int x = 0; x < N; x++) {
            melt[x].assign(M, false);
            air[x].assign(M, 0);
        }

        queue<pair<int, int> > q;
        q.push({0, 0});
        air[0][0] = 2;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (rng(nx, ny, N, M)) continue;
                if (cheese[nx][ny]) continue;
                if (air[nx][ny] == 2) continue;

                air[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
        
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                if (cheese[x][y] == 0) continue;
                int count = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (rng(nx, ny, N, M)) continue;
                    if (cheese[nx][ny]) continue;
                    if (air[nx][ny] != 2) continue;
                    count++;
                }
                if (count >= 2) melt[x][y] = true;
            }
        }

        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                if (cheese[x][y] == 0 || !melt[x][y]) continue;
                cheese[x][y] = 0;
            }
        }

        bool meltable = false;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                if (cheese[x][y] == 1) meltable = true;
            }
        }
        if (!meltable) break;
    }

    cout << res;
    return 0;
}