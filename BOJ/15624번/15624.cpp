#include <iostream>

int arr[1000002];
int main(void) {
    int N;
    std::cin >> N;
    arr[0] = 0;
    arr[1] = 1;
    for (int x = 2; x <= N; x++) arr[x] = (arr[x - 1] + arr[x - 2]) % 1000000007;
    std::cout << arr[N];
    return 0;
}