#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, answer = 3000;
vector<vector<int> > world;
vector<pair<int, int> > pos, tmp;
vector<bool> check;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void search(vector<vector<int> > &w)
{
    vector<vector<int> > m = w;
    queue<pair<int, int> > q;
    for (auto virus : tmp)
    {
        m[virus.first][virus.second] = 1;
        q.push(virus);
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (m[nx][ny] < 0) continue;
            if (m[nx][ny] > 0 && m[nx][ny] <= m[cur.first][cur.second] + 1) continue;

            m[nx][ny] = m[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    int res = 0, res_min = 3000;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            res = max(res, m[x][y] - 1);
            if (m[x][y] >= 0) res_min = min(res_min, m[x][y]);
        }
    }
    if (res_min > 0) answer = min(answer, res);
}

void track(int start, int count)
{
    if (count == M)
    {
        search(world);
        return;
    }

    for (int i = start; i < pos.size(); i++)
    {
        if (check[i]) continue;
        check[i] = true;
        tmp.push_back(pos[i]);
        track(start + 1, count + 1);
        check[i] = false;
        tmp.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    world.resize(N);
    for (int x = 0; x < N; x++)
    {   
        world[x].resize(N);
        for (int y = 0; y < N; y++)
        {
            cin >> world[x][y];
            if (world[x][y] == 1) world[x][y] *= -1;
            else if (world[x][y] == 2)
            {
                world[x][y] = 0;
                pos.push_back({x, y});
            }
        }
    }
    check.assign(pos.size(), false);
    track(0, 0);
    cout << (answer == 3000 ? -1 : answer);
    return 0;
}