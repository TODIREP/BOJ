#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int x, y, skill, cnt;
};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int sx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int sy[8] = {2, 1, -1, -2, 2, 1, -1, -2};
bool vis[302][302][32];
bool rng(int x, int y, int h, int w) {
    return (x < 0 || x >= h || y < 0 || y >= w);
}
int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int K, W, H;
    cin >> K >> W >> H;
    vector<vector<int> > world(H);

    for (int x = 0; x < H; x++) {
        world[x].resize(W);
        for (int y = 0; y < W; y++) {
            cin >> world[x][y];
            if (world[x][y] == 1) world[x][y] = -1;
        }
    }

    queue<node> q;
    q.push({0, 0, 0, 0});
    vis[0][0][0] = true;
    int answer = -1;

    while (!q.empty()) {
        auto cur = q.front();q.pop();

        if (cur.x == H - 1 && cur.y == W - 1) {
            if (answer == -1) answer = cur.cnt;
            else answer = min(answer, cur.cnt);
            continue;
        }

        int ns = cur.skill;
        int nc = cur.cnt + 1;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (rng(nx, ny, H, W) || vis[nx][ny][ns] || world[nx][ny] == -1) continue;
            vis[nx][ny][ns] = true;
            q.push({nx, ny, ns, nc});
        }

        if (ns == K) continue;
        for (int dir = 0; dir < 8; dir++) {
            int nx = cur.x + sx[dir];
            int ny = cur.y + sy[dir];
            if (rng(nx, ny, H, W) || vis[nx][ny][ns + 1] || world[nx][ny] == -1) continue;
            vis[nx][ny][ns + 1] = true;
            q.push({nx, ny, ns + 1, nc});
        }
    }

    cout << answer;
    return 0;
}