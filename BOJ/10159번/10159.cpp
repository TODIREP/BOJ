#include <iostream>
#include <cstring>
using namespace std;

bool item[102][102];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    memset(item, false, sizeof(item));

    int A, B;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        item[A][B] = true;
    }

    for (int check = 1; check <= N; check++)
    {
        for (int x = 1; x <= N; x++)
        {
            if (x == check || !item[x][check]) continue;
            for (int y = 1; y <= N; y++)
            {
                if (y == check || !item[check][y]) continue;
                item[x][y] = true;
            }
        }
    }

    for (int check = 1; check <= N; check++)
    {
        int count = 0;
        for (int x = 1; x <= N; x++)
        {
            if (x == check) continue;
            count += item[x][check];
        }

        for (int y = 1; y <= N; y++)
        {
            if (y == check) continue;
            count += item[check][y];
        }
        cout << N - count - 1 << '\n';
    }

    return 0;
}