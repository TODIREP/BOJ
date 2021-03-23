#include <iostream>
using namespace std;

int N, M, arr[5][5];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char input[6];
    cin >> N >> M;

    for (int x = 0; x < N; x++)
    {
        cin >> input;
        for (int y = 0; y < M; y++)
        {
            arr[x][y] = input[y] - '0';
        }
    }

    int len = (1 << (N * M)), answer = 0;
    for (int S = 0; S < len; S++)
    {
        int sum = 0;

        for (int x = 0; x < N; x++)
        {
            int cur_sum = 0;
            for (int y = 0; y < M; y++)
            {
                int cur = x * M + y;

                if ((S & (1 << cur)) == 0)
                {
                    cur_sum = cur_sum * 10 + arr[x][y];
                }
                else
                {
                    sum += cur_sum;
                    cur_sum = 0;
                }
            }
            sum += cur_sum;
        }

        for (int y = 0; y < M; y++)
        {
            int cur_sum = 0;
            for (int x = 0; x < N; x++)
            {
                int cur = x * M + y;

                if ((S & (1 << cur)) != 0)
                {
                    cur_sum = cur_sum * 10 + arr[x][y];
                }
                else
                {
                    sum += cur_sum;
                    cur_sum = 0;
                }
            }
            sum += cur_sum;
        }
        answer = max(answer, sum);
    }
    cout << answer;
    return 0;
}