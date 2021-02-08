#include <iostream>
#include <stack>
using namespace std;

char num[500001];
stack<char> stk, res;
int main(void) {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int N, K;
    cin >> N >> K;
    cin >> num;

    for (int I = 0; num[I] != '\0'; I++) {
        while (!stk.empty() && (stk.top() < num[I]) && K > 0) {
            stk.pop();
            K--;
        }
        stk.push(num[I]);
    }

    while (K-- > 0) stk.pop();

    while (!stk.empty()) {
        res.push(stk.top());
        stk.pop();
    }
    
    while (!res.empty()) {
        cout << res.top();
        res.pop();
    }
    return 0;
}