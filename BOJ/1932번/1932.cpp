#include <iostream>
using namespace std;

int arr[501][501], sum[501][501];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, result = 0;
    cin >> N;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y <= x; y++) {
            cin >> arr[x][y];
        }
    }
    sum[0][0] = arr[0][0];
    for (int x = 1; x < N; x++) {
        for (int y = 0; y <= x; y++) {
            if (y == 0) sum[x][y] = arr[x][y] + sum[x - 1][y];
            else if (y == x) sum[x][y] = arr[x][y] + sum[x - 1][y - 1];
            else sum[x][y] = arr[x][y] + max(sum[x - 1][y - 1], sum[x - 1][y]);
            result = max(result, sum[x][y]);
        }
    }
    cout << result;
    return 0;
}