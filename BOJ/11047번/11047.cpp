#include <iostream>
using namespace std;

int coin[11];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, K, count = 0, target;
    cin >> N >> K;
    for (int index = 0; index < N; index++) cin >> coin[index];

    for (int index = N - 1; index >= 0; index--) {
        if (coin[index] > K) continue;
        target = K / coin[index];
        count += target;
        K %= coin[index] * target;
    }
    cout << count;
    return 0;
}