#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> f(string target) {
    int str_len = target.size();
    vector<int> arr(str_len);
    int j = 0;
    for (int i = 1; i < str_len; i++) {
        while (j > 0 && target[i] != target[j]) j = arr[j - 1];
        if (target[i] == target[j]) arr[i] = ++j;
    }
    return arr;
}

bool is_valid(vector<int> fail, string target, string cmp) {
    int j = 0, t = target.size(), c = cmp.size();
    for (int i = 0; i < t; i++) {
        while (j > 0 && target[i] != cmp[j]) j = fail[j - 1];
        if (target[i] == cmp[j]) {
            if (j == c - 1) {
                return true;
            } else j++;
        }
    }
    return false;
}

int main(void) {
    string A, B, cmp;
    cin >> A >> B >> cmp;

    vector<int> fail = f(cmp);
    bool b_cmp = is_valid(fail, B, cmp);
    bool a_cmp = is_valid(fail, A, cmp);

    if (b_cmp * a_cmp == 1) cout << "YES";
    else cout << "NO";
    return 0;
}