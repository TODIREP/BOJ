#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct mov {
    int X;
    int Y;
    int R;

    bool operator<(const mov &a) const { return R > a.R; }
};
int INF = 3000;
vector<vector<bool> > room;
vector<vector<int> > dis;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    char input[51];
    int N;
    cin >> N;

    room.resize(N + 1);
    dis.resize(N + 1);
    for (int x = 0; x < N; x++) {
        room[x].resize(N + 1);
        dis[x].assign(N + 1, INF);
        cin >> input;
        for (int y = 0; y < N; y++) {
            room[x][y] = input[y] - '0';
        }
    }

    priority_queue<mov > q;
    dis[0][0] = 0;
    q.push({0, 0, dis[0][0]});

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            int nr = cur.R + (room[nx][ny] == 0);

            if (nr < dis[nx][ny]) {
                dis[nx][ny] = nr;
                q.push({nx, ny, nr});
            }
        }
    }
    cout << dis[N - 1][N - 1];
    return 0;
}