#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main(void) {
    fastio;
    string input;
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> rule;
        map<int, string> res;
        map<string, int> mp;

        for (int index = 0; index < N; index++) {
            cin >> input;
            mp[input] = index;
        }

        for (int index = 0; index < N; index++) {
            cin >> input;
            rule.push_back(mp[input]);
        }

        for (int index = 0; index < N; index++) {
            cin >> input;
            res.insert({rule[index], input});
        }

        for (auto result : res) cout << result.second << " ";
        cout << "\n";
    }
    return 0;
}