#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int M, N, X, Y, ans = -1;
        cin >> M >> N >> X >> Y;

        for (int year = X - 1; year < N * M; year += M)
        {
            if (year % N == Y - 1)
            {
                ans = year + 1;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}