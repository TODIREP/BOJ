#include <iostream>
#include <queue>
using namespace std;

bool world[51][51];
int dis[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void init(int N, int M)
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            dis[x][y] = 30000;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    char input[52];
    cin >> N >> M;

    queue<pair<int, int>> q;
    for (int x = 0; x < N; x++)
    {
        cin >> input;
        for (int y = 0; y < M; y++)
        {
            world[x][y] = (input[y] == 'L');
            if (world[x][y])
            {
                q.push({x, y});
            }
        }
    }

    int answer = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        init(N, M);

        queue<pair<int, int>> check;
        dis[cur.first][cur.second] = 0;
        check.push(cur);

        while (!check.empty())
        {
            auto mov = check.front();
            check.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = mov.first + dx[dir];
                int ny = mov.second + dy[dir];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (!world[nx][ny]) continue;
                if (dis[nx][ny] <= dis[mov.first][mov.second] + 1) continue;

                dis[nx][ny] = dis[mov.first][mov.second] + 1;
                answer = max(answer, dis[nx][ny]);
                check.push({nx, ny});
            }
        }
    }
    cout << answer;
    return 0;
}