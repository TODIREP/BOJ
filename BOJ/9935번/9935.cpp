#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str, explosion;
stack<char> stk, res;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> str >> explosion;

    int len = explosion.size();

    for (int I = 0; str[I] != '\0'; I++) {
        stk.push(str[I]);

        if (stk.top() == explosion[len - 1]) {
            stack<char> tmp;
            bool bomb = true;
            int cur = len;

            while (!stk.empty() && cur-- > 0) {
                tmp.push(stk.top());
                if (stk.top() != explosion[cur]) bomb = false;
                stk.pop();
            }
            if (cur > 0) bomb = false;
            if (!bomb) {
                while (!tmp.empty()) {
                    stk.push(tmp.top());
                    tmp.pop();
                }
            }
        }
    }

    while (!stk.empty()) {
        res.push(stk.top());
        stk.pop();
    }

    if (res.empty()) cout << "FRULA";
    else while (!res.empty()) { cout << res.top(); res.pop(); }
    return 0;
}