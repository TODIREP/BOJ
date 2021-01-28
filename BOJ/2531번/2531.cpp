#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int plate[30002], chobab[3002];
int main(void) {
    fastio;
    int N, D, K, C;
    int res = 0, c_count = 0, p_count = 0;
    cin >> N >> D >> K >> C;
    chobab[C]++;
    for (int index = 0; index < N; index++) cin >> plate[index];
    int start = 0, end = 0;

    p_count++;
    chobab[plate[start]]++;
    if (chobab[plate[start]] == 1) c_count++;
    while (start < N) {
        if (p_count == K) {
            res = max(res, c_count);
            p_count--;
            chobab[plate[start]]--;
            if (chobab[plate[start]] == 0) c_count--;
            start++;
        } else {
            p_count++;
            end++;
            if (end == N) end = 0;
            chobab[plate[end]]++;
            if (chobab[plate[end]] == 1) c_count++;
        }
    }
    cout << res + 1;
    return 0;
}