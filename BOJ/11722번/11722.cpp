#include <iostream>

int arr[1001], LDS[1001];

int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int N, result;
    std::cin >> N;
    for (int index = 0; index < N; index++) {
        std::cin >> arr[index];
    }
    LDS[0] = 1;
    result = LDS[0];

    for (int index = 1; index < N; index++) {
        int front = 0;
        for (int index2 = index; index2 >= 0; index2--) {
            if (arr[index2] <= arr[index]) continue;
            front = max(front, LDS[index2]);
        }
        LDS[index] = front + 1;
        result = max(result, LDS[index]);
    }
    std::cout << result;
    return 0;
}