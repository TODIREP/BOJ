#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    string input;
    cin >> input;

    stack<pair<int, int> > stk;
    int target = 0, counter = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(') {
            if (target > 0) {
                stk.push({target, counter});
                target = 0;
                counter = 0;
            }
            stk.push({-1, -1});
        }

        if (input[i] == ')') {
            if (target > 0) {
                stk.push({target, counter});
                target = 0;
                counter = 0;
            }

            int cur = 0, before = -1;
            while (!stk.empty() && stk.top().first > -1) {
                cur += stk.top().first;
                if (before == -1) before = stk.top().second;
                stk.pop();
            }
            stk.pop();

            int prev = stk.top().first - 1;
            int cnt = stk.top().second;
            stk.pop();
            prev += cnt * cur;
            stk.push({prev, before});
        }

        if (input[i] >= '0' && input[i] <= '9') {
            target++;
            counter = input[i] - '0';
        }
    }

    int res = target;
    while (!stk.empty()) {
        res += stk.top().first;
        stk.pop();
    }
    cout << res;
    return 0;
}