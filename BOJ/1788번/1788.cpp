#include <iostream>
using namespace std;
#define endl "\n"
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int fibo[1000001];
int abs(int num) { return num > 0 ? num : num * -1; }
int main(void) {
    fastio;
    int N;
    fibo[0] = 0;fibo[1] = 1;
    cin >> N;
    int target = abs(N);
    for (int index = 2; index <= target; index++) fibo[index] = (fibo[index - 1] + fibo[index - 2]) % 1000000000;
    if (N >= 0) cout << (fibo[N] != 0) << endl;
    else cout << (target % 2 == 0 ? -1 : 1) << endl;
    cout << fibo[target];
    return 0;
}