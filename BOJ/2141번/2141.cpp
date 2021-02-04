#include <iostream>
#include <algorithm>
using namespace std;

#define lint long long
#define home first
#define people second
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

lint sum[100001];
pair<lint, lint> arr[100001];

lint cal(lint target, lint len) {
    lint check = 0;
    for (int index = 0; index < len; index++) {
        if (arr[index].home > target) return check;
        check += arr[index].people;
    }
    return check;
}

int main(void) {
    fastio;
    lint N;
    cin >> N;
    for (int index = 0; index < N; index++) cin >> arr[index].home >> arr[index].people;
    sort(arr, arr + N);
    sum[0] = arr[0].people;
    for (int index = 1; index < N; index++) sum[index] = sum[index - 1] + arr[index].people;
    
    lint left = arr[0].home, right = arr[N - 1].home, res = __LONG_LONG_MAX__;
    while (left <= right) {
        lint mid = (left + right) / 2;
        
        if (cal(mid, N) * 2 >= sum[N - 1]) {
            res = min(res, mid);
            right = mid - 1;
        } else left = mid + 1;
    }
    cout << res;
    return 0;
}