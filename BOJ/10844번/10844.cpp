#include <iostream>
using namespace std;
#define MOD (long long) 1e9

long long arr[101][11];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    long long result = 0;
    cin >> N;
    for (int index = 1; index <= 9; index++) arr[1][index] = 1;

    for (int index = 2; index <= N; index++) {
        for (int index2 = 0; index2 <= 9; index2++) {
            if (index2 == 0) {
                arr[index][index2] = arr[index - 1][index2 + 1];
            } else if (index2 == 9) {
                arr[index][index2] = arr[index - 1][index2 - 1];
            } else {
                arr[index][index2] = (arr[index - 1][index2 - 1] + arr[index - 1][index2 + 1]) % MOD;
            }
        }
    }
    
    for (int index = 0; index <= 9; index++) {
        result += arr[N][index] % MOD;
    }
    cout << result % MOD;
    return 0;
}