#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

bool sosu[4000002];
int N;
int next(int cur) {
    for (int index = cur + 1; index <= N; index++) if (!sosu[index]) return index;
    return -1;
}
int main(void) {
    fastio;
    int res = 0, sum, start = 2, end = 2;
    cin >> N;
    for (int index = 2; index <= N; index++) {
        if (sosu[index]) continue;
        for (int value = 2; index * value <= N; value++) {
            int target = index * value;
            if (sosu[target]) continue;
            sosu[target] = true;
        }
    }
    sum = start;
    while (end <= N) {
        if (sum == N) {
            res++;
            sum -= start;
            start = next(start);
        } else if (sum < N) {
            end = next(end);
            sum += end;
        } else {
            sum -= start;
            start = next(start);
        }

        if (start > end) {
            while (end > start && end != -1) end = next(end);
            sum += end;
        }
        if (start == -1 || end == -1) break;
    }
    cout << res;
    return 0;
}