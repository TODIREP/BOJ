#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main(void) {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        int N, M, coin[21];
        int target[10001] = { 0 };
        cin >> N;
        for (int index = 0; index < N; index++) cin >> coin[index];
        cin >> M;
        target[0] = 1;
        for (int index = 0; index < N; index++) {
            for (int next = coin[index]; next <= M; next++) target[next] += target[next - coin[index]];
        }
        cout << target[M] << "\n";
    }
    return 0;
}