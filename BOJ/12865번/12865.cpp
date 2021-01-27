#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int bag[101][100001];
int main(void) {
    fastio;
    int N, K, W, V;
    cin >> N >> K;
    for (int index = 0; index < N; index++) {
        cin >> W >> V;
        bag[index][W] = max(bag[index][W], V);
        if (index == 0) for (int cur = W + 1; cur <= K; cur++) bag[index][cur] = bag[index][cur - 1];
        else {
            for (int cur = 0; cur <= K; cur++) {
                if (cur < W) bag[index][cur] = bag[index - 1][cur];
                else {
                    bag[index][cur] = max(bag[index - 1][cur - W] + V, bag[index - 1][cur]);
                }
            }
        }
    }
    cout << bag[N - 1][K];
    return 0;
}