#include <iostream>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int pow(int n) { return n * n; }
int main(void) {
    fastio;
    vector<int> res;
    int N, s = 1, e = 2;
    cin >> N;

    while (e > s) {
        if (pow(e) - pow(s) == N) {
            res.push_back(e);
            e++;
            s++;
        } else if (pow(e) - pow(s) > N) s++;
        else e++;
    }
    if (res.empty()) cout << "-1";
    else for (int num : res) cout << num << "\n";
    return 0;
}