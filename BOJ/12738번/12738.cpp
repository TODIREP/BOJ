#include <iostream>
using namespace std;

int NUM[1000002], RES[1000002], LIS[1000002];
int lower_index(int right, int target) {
    int left = 0;

    while (left < right) {
        int mid = (left + right) / 2;

        if (RES[mid] >= target) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main(void) {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int N;
    cin >> N;
    for (int I = 1; I <= N; I++) cin >> NUM[I];
    int pos = 1;
    RES[0] = -1000000001;
    for (int I = 1; I <= N; I++) {
        if (RES[pos - 1] < NUM[I]) {
            LIS[I] = pos;
            RES[pos++] = NUM[I];
        }
        else {
            int target = lower_index(pos, NUM[I]);
            LIS[I] = target;
            RES[target] = NUM[I];
        }
    }
    int result = 0;
    for (int I = 1; I <= N; I++) result = max(result, LIS[I]);
    cout << result;
    return 0;
}