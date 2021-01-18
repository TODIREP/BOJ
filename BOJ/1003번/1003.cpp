#include <iostream>
using namespace std;

#define fibonacci pair<int, int>
#define zero first
#define one second

fibonacci num[41];
fibonacci fibo(int N) {
    if (N == 0) return {1, 0};
    if (N == 1) return {0, 1};
    if (num[N].zero != -1 && num[N].one != -1) return num[N];
    auto n1 = fibo(N - 1);
    auto n2 = fibo(N - 2);
    num[N] = {n1.zero + n2.zero, n1.one + n2.one};
    return num[N];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int T, N;
    cin >> T;
    for (int x = 0; x < 41; x++) num[x] = {-1, -1};
    while (T--) {
        cin >> N;
        auto result = fibo(N);
        cout << result.zero << " " << result.one << "\n";
    }
    return 0;
}