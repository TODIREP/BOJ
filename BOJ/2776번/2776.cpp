#include <iostream>
#include <unordered_map>
using namespace std;
#define endl "\n"
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main(void) {
    fastio;
    int T, N, M, input;
    cin >> T;

    while (T--) {
        unordered_map<int, bool> res;
        cin >> N;
        while (N--) {
            cin >> input;
            res[input] = true;
        }

        cin >> M;
        while (M--) {
            cin >> input;
            if (res[input]) cout << 1;
            else cout << 0;
            cout << endl;
        }
    }
    return 0;
}