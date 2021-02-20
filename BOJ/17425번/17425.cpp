#include <iostream>
using namespace std;

long long f[1000001], g[1000001];
int main(void)
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T, N;
    cin >> T;

    for (int i = 1; i <= 1000000; i++)
    {
        for (int j = 1; i * j <= 1000000; j++) f[i * j] += i;
    }
    for (int i = 1; i <= 1000000; i++) g[i] = g[i - 1] + f[i];

    while (T--)
    {
        cin >> N;
        cout << g[N] << '\n';
    }

    return 0;
}