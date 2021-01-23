#include <iostream>
using namespace std;
#define lint long long
#define mod (lint) (1e9 + 9)
#define plus(a, b, c) (a + b + c) % mod
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

lint sum[1000002];
int main(void) {
    fastio();
    int T, N;
    cin >> T;
    sum[0] = 1; sum[1] = 2; sum[2] = 4;
    for (int index = 3; index < 1000002; index++) sum[index] = plus(sum[index - 1], sum[index - 2], sum[index - 3]);
    while (T--) {
        cin >> N;
        cout << sum[N - 1] << "\n";
    }
    return 0;
}