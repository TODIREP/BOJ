#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> fail(string target) {
    int target_len = target.size();
    vector<int> f(target_len);

    int j = 0;
    for (int i = 1; i < target_len; i++) {
        while (j > 0 && target[i] != target[j]) j = f[j - 1];
        if (target[i] == target[j]) f[i] = ++j;
    }

    return f;
}
int main(void) {
    string S, P;
    cin >> S >> P;

    vector<int> f = fail(P);

    int j = 0, s_len = S.size(), p_len = P.size();
    for (int i = 0; i < s_len; i++) {
        while (j > 0 && S[i] != P[j]) j = f[j - 1];
        if (S[i] == P[j]) {
            if (j == p_len - 1) {
                cout << 1;
                return 0;
            } else j++;
        }
    }
    cout << 0;
    return 0;
}