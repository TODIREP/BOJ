#include <iostream>
#include <stack>
using namespace std;

stack<int> stk[1002];
int main(void) {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int N, L, H, max_h = 0;
    cin >> N;

    for (int index = 0; index < N; index++) {
        cin >> L >> H;
        max_h = max(max_h, H);
        for (int height = 1; height <= H; height++) {
            if (stk[height].empty()) stk[height].push(L);
            else {
                int prev = stk[height].top();
                if (prev < L) {
                    if (stk[height].size() > 1) stk[height].pop();
                    stk[height].push(L);
                } else {
                    stk[height].pop();
                    stk[height].push(L);
                    stk[height].push(prev);
                }
            }
        }
    }

    int res = 0;
    for (int index = 1; index <= max_h; index++) {
        int max_width = 0, min_width = 1003;
        while (!stk[index].empty()) {
            int width = stk[index].top();
            stk[index].pop();
            min_width = min(min_width, width);
            max_width = max(max_width, width);
        }
        res += max_width - min_width + 1;
    }
    cout << res;
    return 0;
}