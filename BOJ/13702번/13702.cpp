#include <iostream>
using namespace std;
#define lint long long

lint bottle[10001];
int main(void) {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    lint N, K, left = 1, right = 0, res = 0;
    cin >> N >> K;

    for (int index = 0; index < N; index++) {
        cin >> bottle[index];
        right = max(right, bottle[index]);
    }

    while (left <= right) {
        lint mid = (left + right) / 2;

        lint sum = 0;
        for (int index = 0; index < N; index++) sum += bottle[index] / mid;
        
        if (sum >= K) {
            res = max(res, mid);
            left = mid + 1;
        }
        else right = mid - 1;
    }

    cout << res;
    return 0;
}