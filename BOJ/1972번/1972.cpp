#include <iostream>
#include <string>
#include <map>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main(void) {
    fastio;
    string input;
    while (cin >> input) {
        if (!input.compare("*")) return 0;
        bool surprise = true;
        int N = input.size();

        for (int len = 1; len < N; len++) {
            map<string, bool> mp;
            for (int index = 0; index < N; index++) {
                if (index + len >= N) break;
                
                string temp;
                temp.push_back(input[index]);
                temp.push_back(input[index + len]);

                if (mp[temp]) {
                    surprise = false;
                    break;
                } else mp[temp] = true;
            }
            if (!surprise) break;
        }

        cout << input << " is ";
        if (!surprise) cout << "NOT ";
        cout << "surprising.\n";
    }
}