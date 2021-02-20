#include <iostream>
using namespace std;

int main(void) {
    int N;
    while (cin >> N) {
        int before = 0, count = 0;
        while (true) {
            before = (before * 10 + 1) % N;
            count++;
            if (before == 0) break;
        }
        cout << count << '\n';
    }
    return 0;
}