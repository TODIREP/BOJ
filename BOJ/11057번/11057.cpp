#include <iostream>
using namespace std;

int arr[1002][11];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, result = 0;
    cin >> N;

    for (int index = 0; index < 10; index++) arr[1][index] = 1;
    for (int index = 2; index <= N; index++) {
        for (int index2 = 0; index2 < 10; index2++) {
            for (int index3 = 0; index3 <= index2; index3++) {
                arr[index][index2] += arr[index - 1][index3] % 10007;
            }
        }
    }

    for (int index = 0; index < 10; index++) result += arr[N][index] % 10007;
    cout << result % 10007;
    return 0;
}