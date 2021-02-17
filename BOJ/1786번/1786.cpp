#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> pre_kmp(string target) {
    vector<int> pre(target.size());
    int j = 0;
    for (int i = 1; i < target.size(); i++) {
        while (j > 0 && target[i] != target[j]) j = pre[j - 1];
        if (target[i] == target[j]) pre[i] = ++j;
    }
    return pre;
}
int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string T, P;
    getline(cin, T);
    getline(cin, P);

    vector<int> res, fail = pre_kmp(P);

    int N = T.size(), M = P.size();

    int j = 0;
    for (int i = 0; i < N; i++) {
        while (j > 0 && T[i] != P[j]) j = fail[j - 1];
        if (T[i] == P[j]) {
            if (j == M - 1) {
                res.push_back(i - M + 2);
                j = fail[j];
            } else j++;
        }
    }

    cout << res.size() << "\n";
    for (int result: res) cout << result << " ";
    return 0;
}