#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input;
    for (int test = 1; ; test++) {
        cin >> input;
        if (input[0] == '-') break;
        int length = input.length(), result = 0;
        stack<char> data;

        for (int index = 0; index < length; index++) {
            if (input[index] == '{') {
                data.push(input[index]);
            } else {
                if (data.empty()) {
                    result++;
                    data.push('{');
                    continue;
                } else {
                    if (data.top() == '{') {
                        data.pop();
                    }
                }
            }
        }

        while (!data.empty()) {
            char cur = data.top();
            data.pop();
            result++;
            data.pop();
        }

        cout << test << ". " << result << "\n";
    }
    return 0;
}