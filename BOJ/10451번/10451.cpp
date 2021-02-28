#include <iostream>
#include <vector>
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
        int N;
        cin >> N;

        vector<int> per(N + 1);
        for(int i = 1; i <= N; i++)
        {
            cin >> per[i];
        }

        int answer = 0;
        for (int i = 1; i <= N; i++)
        {
            if (per[i] == 0) continue;
            answer++;

            int nxt = i;
            while (nxt != 0)
            {
                int prev = per[nxt];
                per[nxt] = 0;
                nxt = prev;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}