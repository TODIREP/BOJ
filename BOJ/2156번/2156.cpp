#include <iostream>
using namespace std;

int arr[10001];
long long total[10001][2];

int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    long long result;
    cin >> N;
    for (int index = 0; index < N; index++) cin >> arr[index];
    total[0][0] = arr[0];
    total[1][0] = arr[1];
    total[1][1] = arr[0] + arr[1];
    result = total[1][1];

    for (int index = 2; index < N; index++) {
        M = -1;
        for (int index2 = index - 2; index2 >= 0; index2--) {
            M = max(M, max(total[index2][0], total[index2][1]));
        }
        total[index][1] = arr[index] + total[index - 1][0];
        total[index][0] = arr[index] + M;
        result = max(result, max(total[index][1], total[index][0]));
    }
    cout << result;
    return 0;
}