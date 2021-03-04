#include <iostream>
using namespace std;

int N, M, K, chess[11][11], answer = -100000;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool check[11][11];

void search(int start_x, int count, int sum)
{
    if (count == K)
    {
        answer = max(answer, sum);
        return;
    }

    for (int x = start_x; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            if (check[x][y]) continue;
            bool valid = true;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (check[nx][ny]) valid = false;
            }
            if (!valid) continue;

            check[x][y] = true;
            search(x, count + 1, sum + chess[x][y]);
            check[x][y] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            cin >> chess[x][y];
        }
    }

    search(0, 0, 0);

    cout << answer;
    return 0;
}