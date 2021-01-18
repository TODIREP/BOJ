#include <iostream>
using namespace std;

int num[1001], cost[1001];
int search(int N) {
    if (N <= 1) return num[N];
    if (cost[N] > 0) return cost[N];
    for (int index = N - 1; index >= N / 2; index--) {
        cost[N] = max(cost[N], max(num[N], search(N - index) + search(index)));
    }
    return cost[N];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (int index = 1; index <= N; index++) cin >> num[index];
    search(N);
    cout << cost[N];
    return 0;
}