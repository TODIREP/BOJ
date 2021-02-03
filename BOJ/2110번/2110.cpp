#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int router[200001];
int calc(int target, int len) {
    int count = 1, before = router[0];
    for (int index = 1; index < len; index++) {
        if (router[index] - before < target) continue;
        count++;
        before = router[index];
    }
    return count;
}

int main(void) {
    fastio;
    int N, C;
    cin >> N >> C;
    for (int index = 0; index < N; index++) cin >> router[index];
    sort(router, router + N);

    int left = 1, right = router[N - 1] - router[0], answer = 0;
    while (left < right) {
        int mid = (left + right) / 2;
        int count = calc(mid, N);
        
        if (count >= C) {
            answer = max(answer, mid);
            left = mid + 1;
        } else right = mid;
    }
    if (calc(right, N) >= C) answer = max(answer, right);

    cout << answer;
    return 0;
}