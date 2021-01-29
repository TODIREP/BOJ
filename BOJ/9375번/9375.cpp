#include <iostream>
#include <string>
#include <map>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main(void) {
    fastio;
    string item, type;
    int T, N;
    cin >> T;
    while (T--) {
        map<string, int> mp;
        cin >> N;
        for (int index = 0; index < N; index++) {
            cin >> item >> type;
            auto input_type = mp.find(type);
            if (input_type == mp.end()) mp.insert({type, 1});
            else input_type->second++;
        }
        int res = 1;
        for (auto items: mp) res *= (items.second + 1);
        cout << res - 1 << "\n";
    }
    return 0;
}