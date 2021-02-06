#include <iostream>
#include <stack>
using namespace std;

stack<int> stk[8];
int main(void) {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int N, P, A, B, count = 0;
    cin >> N >> P;
    for (int index = 0; index < N; index++) {
        cin >> A >> B;
        if (stk[A].empty()) {
            stk[A].push(B);
            count++;
        } else {
            while (!stk[A].empty() && stk[A].top() > B) {
                stk[A].pop();
                count++;
            }
            if (stk[A].empty() || !stk[A].empty() && stk[A].top() < B) {
                stk[A].push(B);
                count++;
            }
        }
    }
    cout << count;
    return 0;
}