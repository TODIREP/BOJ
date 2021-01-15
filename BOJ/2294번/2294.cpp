#include <iostream>
using namespace std;

int coin[10002];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K, input;
    cin >> N >> K;

    for (int index = 0; index < N; index++) {
        cin >> input;
        if (input <= 10000) coin[input] = 1;
    }

    for (int index = 1; index <= K; index++) {
        int sum = -1;
        for (int index2 = index - 1; index2 >= 1; index2--) {
            if (coin[index2] == 0 || coin[index - index2] == 0) continue;
            int temp = coin[index2] + coin[index - index2];
            if (sum == -1) sum = temp;
            else sum = min(sum, temp);
        }
        if (sum != -1) {
            if (coin[index] == 0) coin[index] = sum;
            else coin[index] = min(sum, coin[index]);
        }
    }
    if (coin[K] == 0) cout << "-1";
    else cout << coin[K];
    return 0;
}