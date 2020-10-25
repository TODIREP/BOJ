#include <iostream>
#include <deque>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, count, isFront;
    string cmd, input;
    cin >> N;

    for (int test = 1; test <= N; test++) {
        isFront = 1;
        deque<string> data;
        cin >> cmd >> count >> input;
        int input_len = input.length();
        string temp = "";
        for (int index = 1; index < input_len - 1; index++) {
            if (input[index] != ',') {
                temp.push_back(input[index]);
            }
            if (input[index] == ',' || index == input_len - 2) {
                data.push_back(temp);
                temp = "";
            }
        }
        int start = 0;
        int end = count > 0 ? count - 1 : 0;
        int cmd_len = cmd.length();
        for (int index = 0; index < cmd_len; index++) {
            if (cmd[index] == 'R') {
                isFront *= -1;
                int temp = start;
                start = end;
                end = temp;
            }
            if (cmd[index] == 'D') {
                if (count == 0) {
                    isFront = 1000;
                    break;
                }
                start += isFront;
                count--;
            }
        }
        if (isFront == 1000) {
            cout << "error\n";
        }
        else {
            int index;
            cout << "[";
            if (count > 0) {
                for (index = start; index != end; index += isFront) {
                    cout << data[index] << ",";
                }
                cout << data[index];
            }
            cout << "]\n";
        }
    }
    return 0;
}