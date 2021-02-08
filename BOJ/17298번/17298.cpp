#include <iostream>
#include <stack>
using namespace std;

int num[1000001], res[1000001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int N;
    cin >> N;
    for (int I = 0; I < N; I++) cin >> num[I];

    stack<int> stk;

    for (int I = N - 1; I >= 0; I--) {
        while (!stk.empty()) {
            if (stk.top() <= num[I]) stk.pop();
            else break;
        }

        if (stk.size() == 0) res[I] = -1;
        else res[I] = stk.top();
        stk.push(num[I]);
    }

    for (int I = 0; I < N; I++) cout << res[I] << " ";
    return 0;
}