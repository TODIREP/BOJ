#include <iostream>
using namespace std;

int NUM[1002], LIS[1002], PRE[1002], RESULT[1002];
int main(void) {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int N;
    cin >> N;
    for (int index = 1; index <= N; index++) cin >> NUM[index];

    LIS[1] = 1;PRE[1] = 0;
    for (int index = 2; index <= N; index++) {
        int max_len = -1, prev_num;
        for (int cur = index - 1; cur >= 0; cur--) {
            if (NUM[index] > NUM[cur]) {
                if (max_len < LIS[cur]) {
                    max_len = LIS[cur];
                    prev_num = cur;
                }
            }
        }
        LIS[index] = max_len + 1;
        PRE[index] = prev_num;
    }
    
    int res = 0, pos = 0;
    for (int index = 1; index <= N; index++) {
        if (res < LIS[index]) {
            res = LIS[index];
            pos = index;
        }
    }

    int cur = NUM[pos], index = res;
    while (cur != 0) {
        RESULT[index--] = cur;
        pos = PRE[pos];
        cur = NUM[pos];
    }

    cout << res << "\n";
    for (int index = 1; index <= res; index++) cout << RESULT[index] << " ";
    return 0;
}