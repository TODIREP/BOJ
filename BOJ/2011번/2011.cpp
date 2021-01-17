#include <iostream>
#include <string>
using namespace std;

string input;
int count[5002];

bool valid(char a, char b) {
    if (a == '0') return false;
    return (a - '0') * 10 + (b - '0') <= 26;
}

int sum(int a, int b) { return (a + b) % 1000000; }
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int index;
    cin >> input;

    count[0] = (input[0] - '0') > 0;
    for (index = 1; input[index] != '\0'; index++) {
        int counter = 0;
        if (valid(input[index - 1], input[index])) {
            if (index < 2) counter = 1;
            else counter = count[index - 2];
        }
        if (input[index] == '0') count[index] = sum(count[index], counter);
        else count[index] = sum(count[index], sum(count[index - 1], counter));
    }
    cout << count[index - 1] << "\n";
    return 0;
}