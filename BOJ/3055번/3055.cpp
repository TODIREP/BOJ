#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool rng(int x, int y)
{
    return (x < 0 or x >= R or y < 0 or y >= C);
}

void search(queue<pair<int, int>> &q, vector<vector<int>> &world)
{
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (rng(nx, ny)) continue;
            if (world[nx][ny] <= world[cur.first][cur.second] + 1) continue;

            world[nx][ny] = world[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char input[52];
    cin >> R >> C;
    
    vector<vector<int>> water(R), sworld(R);
    queue<pair<int, int>> w_q, s_q;
    pair<int, int> destination;

    for (int x = 0; x < R; x++)
    {
        cin >> input;
        water[x].resize(C);
        sworld[x].resize(C);
        for (int y = 0; y < C; y++)
        {
            if (input[y] == '.')
            {
                water[x][y] = 3000;
                sworld[x][y] = 3000;
            }
            else
            {
                water[x][y] = -1;
                sworld[x][y] = -1;
            }

            if (input[y] == '*')
            {
                w_q.push({x, y});
                water[x][y] = 1;
            }
            if (input[y] == 'S')
            {
                s_q.push({x, y});
                sworld[x][y] = 1;
            }
            if (input[y] == 'D')
            {
                destination = {x, y};
            }
        }
    }
    
    search(w_q, water);
    search(s_q, sworld);

    bool valid = false;
    int move = 3000;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = destination.first + dx[dir];
        int ny = destination.second + dy[dir];
        if (rng(nx, ny)) continue;

        if (sworld[nx][ny] > 0 && (water[nx][ny] > sworld[nx][ny] || water[nx][ny] == -1))
        {
            valid = true;
            move = min(move, sworld[nx][ny]);
        }
    }

    if (valid) cout << move;
    else cout << "KAKTUS";

    return 0;
}