#include <iostream>
#include <queue>
using namespace std;

struct robot {
    int x, y, dir;
};

int clean[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool rng(int x, int y, int N, int M)
{
    return (x < 0 || x >= N || y < 0 || y >= M);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int R, C, D;
    cin >> R >> C >> D;

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            cin >> clean[x][y];
        }
    }

    int count = 1;
    queue<robot> q;
    clean[R][C] = 2;
    q.push({R, C, D});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        
        int nxt = cur.dir, stat = 0;
        for (int i = 0; i < 4; i++)
        {
            nxt--;
            if (nxt < 0) nxt = 3;

            int nx = cur.x + dx[nxt];
            int ny = cur.y + dy[nxt];

            if (!rng(nx, ny, N, M) && clean[nx][ny] == 0)
            {
                count++;
                clean[nx][ny] = 2;
                q.push({nx, ny, nxt});
                stat = 1;
                break;
            }
        }

        if (stat > 0) continue;

        int nx = cur.x + dx[cur.dir] * -1;
        int ny = cur.y + dy[cur.dir] * -1;

        if (rng(nx, ny, N, M) || clean[nx][ny] == 1)
        {
            break;
        }
        q.push({nx, ny, cur.dir});
    }

    cout << count;

    return 0;
}