#include <iostream>
using namespace std;

int idle[201], dis[201];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, answer = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> idle[i];

        int max_dis = 0;

        for (int j = i - 1; j >= 0; j--)
        {
            if (idle[i] > idle[j])
            {
                max_dis = max(max_dis, dis[j]);
            }
        }

        dis[i] = max_dis + 1;
        answer = max(answer, dis[i]);
    }

    cout << N - answer;

    return 0;
}