#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int L, P, V;

    for (int i = 1; cin >> L >> P >> V; i++)
    {
        if (L == 0 && P == 0 && V == 0) return 0;
        int answer = (V / P) * L;
        V %= P;
        if (V >= L) answer += L;
        else answer += V;
        cout << "Case " << i << ": " << answer << '\n';
    }
}