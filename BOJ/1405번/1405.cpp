#include <iostream>
#include <iomanip>
using namespace std;

bool vis[30][30];
int M;
double res = 0.0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int value[4];

void mov(int x, int y, double cur, int cnt)
{
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx > 28 || ny < 0 || ny > 28) continue;

        int nct = cnt + 1;
        double ncur = cur * (value[dir] / (double) 100);

        if (vis[nx][ny])
        {
            res += ncur;
        }
        else
        {
            if (nct == M) continue;
            vis[nx][ny] = true;
            mov(nx, ny, ncur, nct);
            vis[nx][ny] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M;
    for (int x = 0; x < 4; x++)
    {
        cin >> value[x];
    }
    vis[14][14] = true;
    mov(14, 14, 1.0, 0);
    cout << fixed;
    cout.precision(11);
    cout << (double) 1 - res;
    return 0;
}