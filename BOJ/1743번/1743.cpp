#include <iostream>
using namespace std;

int N, M, K, ans = 0;
bool path[101][101];

void search(int x, int y)
{
    ans++;
    path[x][y] = false;

    if (x + 1 < N && path[x + 1][y])
    {
        search(x + 1, y);
    }

    if (y + 1 < M && path[x][y + 1])
    {
        search(x, y + 1);
    }

    if (x - 1 >= 0 && path[x - 1][y])
    {
        search(x - 1, y);
    }

    if (y - 1 >= 0 && path[x][y - 1])
    {
        search(x, y - 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    int R, C;
    for (int i = 0; i < K; i++)
    {
        cin >> R >> C;
        path[R - 1][C - 1] = true;
    }

    int result = 0;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            if (!path[x][y]) continue;
            ans = 0;
            search(x, y);
            result = max(result, ans);
        }
    }

    cout << result;
    return 0;
}