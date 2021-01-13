#include <iostream>
using namespace std;

int arr[1001], LIS[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, result;
    cin >> N;
    for (int index = 0; index < N; index++) {
        cin >> arr[index];
    }
    LIS[0] = arr[0];
    result = LIS[0];

    for (int index = 1; index < N; index++) {
        int front = 0;
        for (int index2 = index; index2 >= 0; index2--) {
            if (arr[index2] >= arr[index]) continue;
            front = max(front, LIS[index2]);
        }
        LIS[index] = front + arr[index];
        result = max(result, LIS[index]);
    }
    cout << result;
    return 0;
}