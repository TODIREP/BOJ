#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> f(string target) {
    int len = target.size();
    vector<int> fail(len);
    int j = 0, res = 0;
    for (int i = 1; i < len; i++) {
        while (j > 0 && target[i] != target[j]) j = fail[j - 1];
        if (target[i] == target[j]) fail[i] = ++j;
        res = max(res, fail[i]);
    }
    return fail;
}

int main(void) {
    string input;
    cin >> input;

    int len = input.size(), res = 0;
    for (int i = 0; i < len; i++) {
        string target = "";
        for (int index = i; index < len; index++) target.push_back(input[index]);
        vector<int> fail = f(target);
        for (int i = 0; i < fail.size(); i++) res = max(res, fail[i]);
    }
    cout << res;
    return 0;
}