#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string input;
    char change[131];
    string target = "1 234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
    string target2 = "` 1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";

    for (int index = 0; target[index] != '\0'; index++) {
        change[target[index]] = target2[index];
    }

    while (getline(cin, input)) {
        for (int index = 0; input[index] != '\0'; index++) {
            cout << change[input[index]];
        }
        cout << "\n";
    }

    return 0;
}