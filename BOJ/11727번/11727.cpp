#include <iostream>

int main(void) {
    int N, arr[1001];
    std::cin >> N;
    arr[1] = 1;
    arr[2] = 3;
    for (int index = 3; index <= N; index++) {
        arr[index] = (arr[index - 1] + 2 * arr[index - 2]) % 10007;
    }
    std::cout << arr[N];
    return 0;
}