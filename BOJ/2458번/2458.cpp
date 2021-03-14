#include <iostream>
using namespace std;

bool link[501][501];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int A, B;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        link[A][B] = true;
    }

    for (int check = 1; check <= N; check++)
    {
        for (int x = 1; x <= N; x++)
        {
            if (x == check || !link[x][check]) continue;
            for (int y = 1; y <= N; y++)
            {
                if (y == check || !link[check][y]) continue;
                link[x][y] = true;
            }
        }
    }

    int answer = 0;
    for (int check = 1; check <= N; check++)
    {
        int count = 0;
        for (int y = 1; y <= N; y++)
        {
            if (y == check) continue;
            count += link[check][y];
        }
        for (int x = 1; x <= N; x++)
        {
            if (x == check) continue;
            count += link[x][check];
        }
        answer += (count == N - 1);
    }
    cout << answer;

    return 0;
}