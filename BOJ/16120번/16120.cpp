#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input;
    int count[2] = {0, 0};
    cin >> input;

    for (int index = 0; input[index] != '\0'; index++) {
        if (input[index] == 'A') {
            if (count[0] < 2) {
                count[1] = 1000001;
                break;
            }
            count[1]++;
        } else {
            if (count[0] >= 2 && count[1] == 1) {
                count[0]--;
                count[1] = 0;
            } else {
                count[0]++;
            }
        }
    }
    if (count[0] == 1 && count[1] == 0) cout << "PPAP";
    else cout << "NP";
    return 0;
}