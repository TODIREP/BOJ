#include <iostream>
using namespace std;
#define endl "\n"
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int count[1000002], mov[1000002];
int main(void) {
    fastio
    int N;
    cin >> N;
    for (int num = 1; num < N; num++) {
        if (num + 1 <= N) {
            if (count[num + 1] == 0 || count[num + 1] > count[num] + 1) {
                count[num + 1] = count[num] + 1;
                mov[num + 1] = num;
            }
        }

        if (num * 2 <= N) {
            if (count[num * 2] == 0 || count[num * 2] > count[num] + 1) {
                count[num * 2] = count[num] + 1;
                mov[num * 2] = num;
            }
        }

        if (num * 3 <= N) {
            if (count[num * 3] == 0 || count[num * 3] > count[num] + 1) {
                count[num * 3] = count[num] + 1;
                mov[num * 3] = num;
            }
        }
    }
    cout << count[N] << endl;
    int next = N;
    while (next > 0) {
        cout << next << " ";
        next = mov[next];
    }
    return 0;
}