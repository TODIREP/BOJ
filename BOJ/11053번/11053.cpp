#include <iostream>
using namespace std;

int arr[1001];
int LIS[1001];

int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, result = 1;
    cin >> N;
    for (int index = 0; index < N; index++) {
        cin >> arr[index];
    }
    LIS[0] = 1;

    for (int index = 1; index < N; index++) {
        int front = 0;
        for (int index2 = index; index2 >= 0; index2--) {
            if (arr[index2] >= arr[index]) continue;
            front = max(front, LIS[index2]);
        }
        LIS[index] = front + 1;
        result = max(result, LIS[index]);
    }
    cout << result;
    return 0;
}