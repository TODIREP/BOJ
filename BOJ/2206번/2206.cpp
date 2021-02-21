#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int row, col;
    bool wall;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    char input[1001];
    int N, M;
    cin >> N >> M;
    vector<vector<int> > world(N), dis[2];

    dis[0].resize(N);
    dis[1].resize(N);
    for (int x = 0; x < N; x++) {
        world[x].resize(M);
        dis[0][x].assign(M, 100000000);
        dis[1][x].assign(M, 100000000);
        cin >> input;
        for (int y = 0; y < M; y++) {
            world[x][y] = input[y] - '0';
            if (world[x][y] == 1) world[x][y] = -1;
        }
    }

    queue<node> q;
    q.push({0, 0, true});
    dis[0][0][0] = dis[1][0][0] = 1;

    int answer = -1;
    while (!q.empty()) {
        auto cur = q.front();q.pop();
        
        if (cur.row == N - 1 && cur.col == M - 1) {
            if (answer == -1) answer = dis[cur.wall][cur.row][cur.col];
            else answer = min(answer, dis[cur.wall][cur.row][cur.col]);
            continue;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.row + dx[dir];
            int ny = cur.col + dy[dir];
            bool nw = cur.wall;
            int nd = dis[nw][cur.row][cur.col] + 1;

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (nw && world[nx][ny] == -1) nw = false;
            else if (!nw && world[nx][ny] == -1) continue;

            if (dis[nw][nx][ny] <= nd) continue;
            dis[nw][nx][ny] = nd;
            q.push({nx, ny, nw});
        }
    }
    cout << answer;
    return 0;
}