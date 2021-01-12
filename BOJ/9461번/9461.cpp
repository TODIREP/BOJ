#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long result[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };
    int T, N;
    cin >> T;
    for (int index = 11; index <= 100; index++) {
        result[index] = result[index - 5] + result[index - 1];
    }
    while (T--) {
        cin >> N;
        cout << result[N] << "\n";
    }
    return 0;
}