#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, result = 0;
    string input;
    cin >> N;
    while (N--) {
        cin >> input;
        int length = input.length();
        stack<char> data;

        for (int index = 0; index < length; index++) {
            if (data.empty()) {
                data.push(input[index]);
                continue;
            }
            if (data.top() != input[index]) data.push(input[index]);
            else {
                data.pop();
            }
        }
        if (data.empty()) {
            result++;
        }
    }
    cout << result;
    return 0;
}