#include <iostream>
using namespace std;

int count[42];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, input, result = 1, prev = 0;
    cin >> N >> M;
    count[0] = 1; count[1] = 1;
    for (int index = 2; index <= N; index++) count[index] = count[index - 1] + count[index - 2];
    for (int index = 0; index < M; index++) {
        cin >> input;
        result *= count[input - prev - 1];
        prev = input;
    }
    cout << result * count[N - prev];
    return 0;
}