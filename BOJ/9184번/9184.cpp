#include <iostream>
using namespace std;

int arr[21][21][21];
int result(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return arr[0][0][0];
    if (a > 20 || b > 20 || c > 20) return result(20, 20, 20);
    if (arr[a][b][c] != 0) return arr[a][b][c];
    if (a < b && b < c) {
        arr[a][b][c] = result(a, b, c - 1) + result(a, b - 1, c - 1) - result(a, b - 1, c);
        return arr[a][b][c];
    }
    arr[a][b][c] = result(a - 1, b, c) + result(a - 1, b - 1, c) + result(a - 1, b, c - 1) - result(a - 1, b - 1, c - 1);
    return arr[a][b][c];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    arr[0][0][0] = 1;
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) return 0;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << result(a, b, c) << "\n";
    }
}