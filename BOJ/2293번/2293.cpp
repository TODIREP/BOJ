#include <iostream>
using namespace std;

int count[10001], num[101];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    for (int index = 0; index < N; index++) cin >> num[index];

    count[0] = 1;
    for (int x = 0; x < N; x++) {
        for (int y = num[x]; y <= K; y++) count[y] += count[y - num[x]];
    }
    cout << count[K];
    return 0;
}