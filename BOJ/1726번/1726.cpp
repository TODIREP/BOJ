#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int x, y, my_dir;
};

int get_dir(int a, int b)
{
    if (a == b) return 0;
    int f = min(a, b), s = max(a, b);
    if (s % 2 == 0 && s - f == 1) return 2;
    return 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int M, N;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    cin >> M >> N;

    vector<vector<int>> world(M);
    vector<vector<vector<int>>> dis(M);

    for (int x = 0; x < M; x++)
    {
        dis[x].resize(N);
        world[x].resize(N);
        for (int y = 0; y < N; y++)
        {
            dis[x][y].assign(5, 1000000);
            cin >> world[x][y];
        }
    }

    int sx, sy, sd, count = 10000000;
    cin >> sx >> sy >> sd;
    sx--;sy--;
    int rx, ry, dd;
    cin >> rx >> ry >> dd;
    rx--;ry--;

    queue<node> q;
    for (int i = 1; i <= 4; i++)
    {
        dis[sx][sy][i] = 0;
    }
    q.push({sx, sy, sd});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur.x == rx && cur.y == ry)
        {
            if (dis[rx][ry][dd] == 0) dis[rx][ry][dd] = get_dir(cur.my_dir, dd);
            else dis[rx][ry][dd] = min(dis[rx][ry][dd], dis[cur.x][cur.y][cur.my_dir] + get_dir(cur.my_dir, dd));
            count = min(count, dis[rx][ry][dd]);
            continue;
        }

        for (int nxt = 1; nxt <= 4; nxt++)
        {
            int nd = get_dir(cur.my_dir, nxt);
            int ncnt = dis[cur.x][cur.y][cur.my_dir] + nd + 1;

            for (int i = 1; i <= 3; i++)
            {
                int nx = cur.x + i * dx[nxt - 1];
                int ny = cur.y + i * dy[nxt - 1];
                bool valid = false;
                if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

                for (int k = 1; k <= i; k++)
                {
                    int kx = cur.x + k * dx[nxt - 1];
                    int ky = cur.y + k * dy[nxt - 1];

                    if (world[kx][ky] == 1)
                    {
                        valid = true;
                        break;
                    }
                }
                if (valid || dis[nx][ny][nxt] <= ncnt) continue;
                dis[nx][ny][nxt] = ncnt;
                q.push({nx, ny, nxt});
            }
        }
    }
    cout << count;
    return 0;
}