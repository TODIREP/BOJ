#include <iostream>
#include <stack>
using namespace std;
#define lint long long

int building[80001];
stack<pair<int, int>> stk;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    lint N, result = 0;
    cin >> N;

    for (int I = 0; I < N; I++) cin >> building[I];
    for (int I = N - 1; I >= 0; I--) {
        lint res = 0;
        while (!stk.empty()) {
            if (stk.top().first < building[I]) {
                if (stk.top().second != 0) res += stk.top().second;
                res++;
                stk.pop();
            } else break;
        }
        stk.push({building[I], res});
        
        result += res;
    }
    cout << result;
    return 0;
}