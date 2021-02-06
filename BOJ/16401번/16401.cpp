#include <iostream>
using namespace std;

int cookie[1000001];
int main(void) {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int M, N, left = 1, right = 0, res = 0;
    cin >> M >> N;
    for (int index = 0; index < N; index++) {
        cin >> cookie[index];
        right = max(right, cookie[index]);
    }
    while (left <= right) {
        int mid = (left + right) / 2;

        int sum = 0;
        for (int index = 0; index < N; index++) sum += cookie[index] / mid;
        
        if (sum >= M) {
            res = max(res, mid);
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << res;
    return 0;
}