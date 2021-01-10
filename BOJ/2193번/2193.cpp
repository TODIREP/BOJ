#include <iostream>
using namespace std;

long long arr[92][2];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    arr[1][1] = 1;

    for (int index = 2; index <= N; index++) {
        arr[index][0] = arr[index - 1][0] + arr[index - 1][1];
        arr[index][1] = arr[index - 1][0];
    }

    cout << arr[N][0] + arr[N][1];
    return 0;
}