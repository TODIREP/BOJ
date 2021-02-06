#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isNum(string target) { return target[0] >= '0' && target[0] <= '9'; }
string push_num(stack<string> &target, int number) {
    int prev_num;
    int next_number = number;
    while (!target.empty() && isNum(target.top())) {
        prev_num = stoi(target.top());
        target.pop();
        next_number += prev_num;
    }
    return to_string(next_number);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    char input;
    int next_num, prev_num;
    stack<string> stk;
    while ((input = getchar()) != '\n') {
        if (input == '(' || input == '[') {
            string temp = "";
            temp.push_back(input);
            stk.push(temp);
            
        } else if (input == ')') {
            if (stk.empty()) {
                cout << 0;
                return 0;
            }
            string prev = stk.top();
            if (prev.compare("(") == 0) {
                stk.pop();
                stk.push(push_num(stk, 2));
            } else if (isNum(prev)) {
                prev_num = stoi(prev);
                stk.pop();
                next_num = prev_num * 2;

                string next_nums = push_num(stk, next_num);
                if (stk.empty()) {
                    cout << 0;
                    return 0;
                }
                if (stk.top().compare("(") == 0) {
                    stk.pop();
                    stk.push(push_num(stk, stoi(next_nums)));
                } else {
                    cout << 0;
                    return 0;
                }
            } else {
                cout << 0;
                return 0;
            }

        } else if (input == ']') {
            if (stk.empty()) {
                cout << 0;
                return 0;
            }
            string prev = stk.top();
            if (prev.compare("[") == 0) {
                stk.pop();
                stk.push(push_num(stk, 3));
            } else if (isNum(prev)) {
                prev_num = stoi(prev);
                stk.pop();
                next_num = prev_num * 3;
                
                string next_nums = push_num(stk, next_num);
                if (stk.empty()) {
                    cout << 0;
                    return 0;
                }
                if (stk.top().compare("[") == 0) {
                    stk.pop();
                    stk.push(push_num(stk, stoi(next_nums)));
                } else {
                    cout << 0;
                    return 0;
                }
            } else {
                cout << 0;
                return 0;
            }
        }
    }
    if (stk.size() > 1 || !isNum(stk.top())) cout << 0;
    else cout << stk.top();
    return 0;
}