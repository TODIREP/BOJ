#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

bool sosu[10001];
int main(void) {
    fastio;
    int N, num;
    cin >> N;

    for (num = 2; num <= 10000; num++) {
        if (sosu[num]) continue;
        for (int level = 2; num * level <= 10000; level++) {
            if (sosu[num * level]) continue;
            sosu[num * level] = true;
        }
    }

    while (N--) {
        cin >> num;
        for (int number = num / 2; number >= 2; number--) {
            if (sosu[number]) continue;
            if (!sosu[number] && !sosu[num - number]) {
                cout << number << " " << num - number << "\n";
                break;
            }
        }
    }
    return 0;
}