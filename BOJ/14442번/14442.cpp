#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool world[1001][1001];
int dis[1001][1001][11];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M, K;
    char input[1005];
    cin >> N >> M >> K;

    for (int x = 0; x < N; x++)
    {
        cin >> input;
        for (int y = 0; y < M; y++) world[x][y] = (input[y] == '1');
    }

    queue<pair<pair<int, int>, int>> q;
    dis[0][0][0] = 1;
    q.push({{0, 0}, 0});

    while (!q.empty())
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cw = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            int nw = cw;
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (world[nx][ny]) nw++;
            if (nw > K || (dis[nx][ny][nw] != 0 && dis[nx][ny][nw] <= dis[cx][cy][cw] + 1)) continue;

            dis[nx][ny][nw] = dis[cx][cy][cw] + 1;
            q.push({{nx, ny}, nw});
        }
    }

    int ans = 10000000;
    for (int i = 0; i <= K; i++)
    {
        if (dis[N - 1][M - 1][i] == 0) continue;
        ans = min(ans, dis[N - 1][M - 1][i]);
    }
    cout << (ans == 10000000 ? -1 : ans);
    return 0;
}