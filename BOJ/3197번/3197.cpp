#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int world[1502][1502], num[1502][1502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int root[1200000];

int find_root(int n)
{
    if (root[n] < 0) return n;
    return root[n] = find_root(root[n]);
}

void union_root(int a, int b)
{
    a = find_root(a);
    b = find_root(b);
    if (a == b) return;
    root[b] = a;
}

bool compare_root(int a, int b)
{
    a = find_root(a);
    b = find_root(b);
    return (a == b);
}

bool rng(int x, int y, int n, int m)
{
    return (x < 0 || x >= n || y < 0 || y >= m);
}

struct node
{
    int x, y, cnt, t;
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int R, C, pos[2], index = 0;
    char input[1502];
    memset(num, 0, sizeof(num));
    memset(root, -1, sizeof(root));
    cin >> R >> C;

    for (int x = 0; x < R; x++)
    {
        cin >> input;
        for (int y = 0; y < C; y++)
        {
            if (input[y] == '.')
            {
                world[x][y] = 0;
            }
            else if (input[y] == 'X')
            {
                world[x][y] = -1;
                num[x][y] = -1;
            }
            else
            {
                world[x][y] = -2;
            }
        }
    }
    
    queue<node> q;
    queue<pair<int, int>> check;
    int cnt = 0;
    for (int x = 0; x < R; x++)
    {
        for (int y = 0; y < C; y++)
        {
            if (num[x][y] == 0)
            {
                num[x][y] = ++cnt;
                if (world[x][y] == -2)
                {
                    pos[index] = cnt;
                    world[x][y] = 0;
                    index++;
                }
                check.push({x, y});

                while (!check.empty())
                {
                    auto cur = check.front();
                    check.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (rng(nx, ny, R, C)) continue;
                        if (num[nx][ny] == -1)
                        {
                            q.push({nx, ny, num[x][y], 0});
                        }
                        if (num[nx][ny] != 0) continue;

                        num[nx][ny] = cnt;
                        if (world[nx][ny] == -2)
                        {
                            pos[index] = cnt;
                            world[nx][ny] = 0;
                            index++;
                        }
                        check.push({nx, ny});
                    }
                }
            }
        }
    }

    int answer = 0;
    while (!compare_root(pos[0], pos[1]))
    {
        while (!q.empty())
        {
            int cx = q.front().x;
            int cy = q.front().y;
            int cur_cnt = q.front().cnt;
            int cur_time = q.front().t;
            if (cur_time != answer) break;
            q.pop();

            if (world[cx][cy] == -1)
            {
                world[cx][cy] = 0;
                num[cx][cy] = cur_cnt;

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cx + dx[dir];
                    int ny = cy + dy[dir];

                    if (rng(nx, ny, R, C)) continue;
                    if (world[nx][ny] == -1)
                    {
                        q.push({nx, ny, cur_cnt, cur_time + 1});
                    }
                    else
                    {
                        union_root(num[nx][ny], cur_cnt);
                    }
                }
            }
            else
            {
                union_root(num[cx][cy], cur_cnt);
            }
        }
        answer++;
    }
    cout << answer;

    return 0;
}