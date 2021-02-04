#include <iostream>
using namespace std;
#define lint long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

lint late[100001];
int main(void) {
    fastio;
    lint N, M, high = 0;
    cin >> N >> M;
    for (int index = 0; index < N; index++) {
        cin >> late[index];
        high = max(high, late[index]);
    }
    lint left = 0, right = high * M, res = __LONG_LONG_MAX__;

    while (left <= right) {
        lint mid = (left + right) / 2;

        lint sum = 0;
        for (int index = 0; index < N; index++)
            sum += mid / late[index];
        
        if (sum >= M) {
            res = min(res, mid);
            right = mid - 1;
        } else left = mid + 1;
    }
    cout << res;
    return 0;
}