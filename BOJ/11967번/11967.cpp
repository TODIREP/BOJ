#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int LIMIT = 101;
bool world[LIMIT][LIMIT], vis[LIMIT][LIMIT];
vector<pair<int, int>> root[LIMIT][LIMIT];
int N, dx[4] = {1, 0, -1, 0}, answer = 1;
int dy[4] = {0, 1, 0, -1};

bool rng(int x, int y)
{
    return (x < 0 || x >= N || y < 0 || y >= N);
}

void search(int x, int y)
{
    for (auto nxt : root[x][y])
    {
        int nx = nxt.first;
        int ny = nxt.second;

        if (world[nx][ny]) continue;
        world[nx][ny] = true;
        answer++;

        for (int dir = 0; dir < 4; dir++)
        {
            int rx = nx + dx[dir];
            int ry = ny + dy[dir];

            if (rng(rx, ry)) continue;
            if (!vis[rx][ry]) continue;

            vis[nx][ny] = true;
            search(nx, ny);
            break;
        }
    }

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (rng(nx, ny)) continue;
        if (world[nx][ny] && !vis[nx][ny])
        {
            vis[nx][ny] = true;
            search(nx, ny);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M;
    cin >> N >> M;

    int X, Y, A, B;
    for (int i = 0; i < M; i++)
    {
        cin >> X >> Y >> A >> B;
        root[X - 1][Y - 1].push_back({A - 1, B - 1});
    }
    
    vis[0][0] = true;
    world[0][0] = true;
    search(0, 0);
    cout << answer;
    return 0;
}