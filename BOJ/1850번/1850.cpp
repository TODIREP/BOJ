#include <iostream>
using namespace std;
#define lint long long
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

lint GCD(lint a, lint b) { return b ? GCD(b, a % b) : a; }
int main(void) {
    fastio();
    lint A, B, res;
    cin >> A >> B;
    res = GCD(A, B);
    while(res--) cout << "1";
    return 0;
}