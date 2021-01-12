#include <iostream>
using namespace std;

int arr[1000002][2];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    arr[1][1] = 1;
    arr[2][0] = 1;
    arr[2][1] = 1;
    for (int index = 3; index <= N; index++) {
        arr[index][0] = (arr[index - 2][0] + arr[index - 2][1]) % 15746;
        arr[index][1] = (arr[index - 1][0] + arr[index - 1][1]) % 15746;
    }
    cout << (arr[N][0] + arr[N][1]) % 15746;
    return 0;
}