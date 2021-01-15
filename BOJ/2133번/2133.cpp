#include <iostream>
using namespace std;

int arr[32];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    arr[2] = 3;
    for (int index = 3; index <= N; index++) {
        if (index % 2 == 1) continue;
        arr[index] = 2 + arr[index - 2] * 3;
        for (int index2 = 4; index - index2 > 0; index2 += 2) {
            arr[index] += arr[index - index2] * 2;
        }
    }
    cout << arr[N];
    return 0;
}