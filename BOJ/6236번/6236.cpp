#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int cach[100001];
int main(void)
{
    fastio;
    int N, M, S = 0;
    cin >> N >> M;

    for (int I = 0; I < N; I++)
    {
        cin >> cach[I];
        S += cach[I];
    }

    int L = 0, R = S, A = S;

    while (L < R)
    {
        int m = (L + R) / 2;

        int C = 1, cur = m;
        
        for (int I = 0; I < N; I++)
        {
            if (cur - cach[I] < 0 || N - I == M - C) {
                C++;
                cur = m;
            }

            cur -= cach[I];
            if (cur < 0) {
                C = M + 1;
                break;
            }
        }
        
        if (C == M) A = min(A, m);
        if (C > M) L = m + 1;
        else if (C <= M) R = m;
    }

    cout << A;
    return 0;
}