#include <iostream>

int num[1001][1001];

int result(int A, int B) {
    if (B == 0 || A == B) return 1;
    if (num[A][B] != 0) return num[A][B];
    num[A][B] = (result(A - 1, B - 1) + result(A - 1, B)) % 10007;
    return num[A][B];
}

int main(void) {
    int N, K;
    std::cin >> N >> K;
    std::cout << result(N, K);
    return 0;
}