#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void get_distance(vector<vector<int> > &world, vector<vector<int> > &dis, int sx, int sy) {
    for (int x = 0; x < N; x++) dis[x].assign(N, 1000000000);
    queue<pair<int, int> > q;
    q.push({sx, sy});
    dis[sx][sy] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (world[nx][ny] == 1) continue;
            if (dis[nx][ny] <= dis[cur.first][cur.second] + 1) continue;
            dis[nx][ny] = dis[cur.first][cur.second] + 1;

            q.push({nx, ny});
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int L;
    cin >> N >> M >> L;

    vector<vector<int> > course(N);
    for (int x = 0; x < N; x++) {
        course[x].resize(N);
        for (int y = 0; y < N; y++) {
            cin >> course[x][y];
        }
    }

    int sx, sy;
    cin >> sx >> sy;
    sx--;sy--;

    vector<pair<pair<int, int>, pair<int, int> > > pass;
    vector<bool> check;
    int px, py, dx, dy;
    for (int i = 0; i < M; i++) {
        cin >> px >> py >> dx >> dy;
        pass.push_back({{px - 1, py - 1}, {dx - 1, dy - 1}});
        check.push_back(false);
    }
    
    for (int i = 0; i < M; i++) {
        vector<vector<int> > dis(N);
        get_distance(course, dis, sx, sy);

        int nx = -1, ny = -1, nd = 100000000, index = -1;
        for (int x = 0; x < M; x++) {
            if (check[x]) continue;
            auto target = pass[x].first;

            if (dis[target.first][target.second] < nd) {
                index = x;
                nx = target.first;
                ny = target.second;
                nd = dis[target.first][target.second];

            } else if (dis[target.first][target.second] == nd) {
                if (target.first == nx) {
                    if (target.second < ny) {
                        ny = target.second;
                        index = x;
                    }
                } else if (target.first < nx) {
                    nx = target.first;
                    ny = target.second;
                    index = x;
                }
            }
        }
        L -= nd;
        if (index == -1 || L < 0) {
            cout << -1;
            return 0;
        }
        check[index] = true;
        get_distance(course, dis, nx, ny);
        int tx = pass[index].second.first, ty = pass[index].second.second;
        if (L - dis[tx][ty] < 0) {
            cout << -1;
            return 0;
        }
        L += dis[tx][ty];
        sx = tx;
        sy = ty;
    }

    cout << L;
    return 0;
}