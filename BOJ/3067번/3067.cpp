#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, coin[21];
        cin >> N;

        for (int i = 0; i < N; i++)
        {
            cin >> coin[i];
        }

        int M;
        cin >> M;
        vector<int> cnt(M + 1, 0);

        for (int i = 0; i < N; i++)
        {
            cnt[coin[i]] += 1;

            for (int j = coin[i] + 1; j <= M; j++)
            {
                cnt[j] += cnt[j - coin[i]];
            }
        }

        cout << cnt[M] << '\n';
    }
}