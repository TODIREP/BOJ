#include <iostream>
#include <map>
using namespace std;
#define lint long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

lint N, P, Q;
map<lint, lint> mp;
lint unlimit(lint num) {
    if (mp.find(num) != mp.end()) return mp[num];
    mp.insert({num, unlimit(num / P) + unlimit(num / Q)});
    return mp[num];
}

int main(void) {
    fastio;
    cin >> N >> P >> Q;
    mp.insert({0, 1});
    cout << unlimit(N);
    return 0;
}