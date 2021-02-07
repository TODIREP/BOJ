#include <iostream>
using namespace std;
#define lint long long

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    lint N, K;
    cin >> N >> K;
    lint left = 1, right = N * N;

    while (left <= right) {
        lint mid = (left + right) / 2;

        lint S = 0;
        for (int index = 1; index <= N; index++) {
            lint L = 1, R = N;

            while (L < R) {
                lint M = (L + R) / 2;
                if (index * M >= mid) R = M;
                else L = M + 1;
            }
            if (index * L >= mid) L--;
            S += L;
        }
        if (S >= K) right = mid - 1;
        else left = mid + 1;
    }
    cout << right;
    return 0;
}