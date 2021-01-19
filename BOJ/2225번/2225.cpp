#include <iostream>
using namespace std;
#define mod (int) 1e9
#define plus(a, b) (a + b) % mod

int count[201][201];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    for (int index = 0; index <= N; index++) count[0][index] = 1;
    for (int index = 1; index < K; index++) {
        for (int num = 0; num <= N; num++) {
            for (int target = 0; target <= N; target++) {
                if (target + num > N) continue;
                count[index][num + target] = plus(count[index][num + target], count[index - 1][num]);
            }
        }
    }
    cout << count[K - 1][N];
    return 0;
}