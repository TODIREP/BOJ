#include <iostream>
#include <stack>
using namespace std;
#define lint long long

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    lint N, num, res = 0;
    cin >> N;
    stack<pair<lint, lint>> stk;

    for (lint I = 0; I < N; I++) {
        cin >> num;
        lint W = 0;
        while (!stk.empty()) {
            auto target = stk.top();
            if (target.first >= num) {
                if (target.second == 0) W++;
                else W += target.second;
                res = max(res, target.first * W);
                stk.pop();
            } else break;
        }
        W++;
        res = max(res, num * W);
        stk.push({num, W});
    }

    lint before = 0;
    while (!stk.empty()) {
        auto target = stk.top();
        res = max(res, target.first * (target.second + before));
        before += target.second;
        stk.pop();
    }
    cout << res;
    return 0;
}