#include <iostream>
using namespace std;

int arr[1001][3];
int price[1001][3];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, mini;
    cin >> N;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < 3; y++) {
            cin >> arr[x][y];
            if (x == 0) price[0][y] = arr[x][y];
        }
    }

    for (int x = 1; x < N; x++) {
        for (int y = 0; y < 3; y++) {
            mini = 1e9;
            for (int p = 0; p < 3; p++) {
                if (p == y) continue;
                if (mini >= price[x - 1][p]) mini = price[x - 1][p];
            }
            price[x][y] = arr[x][y] + mini;
        }
    }
    mini = 1e9;
    for (int x = N - 1; x < N; x++) {
        for (int y = 0; y < 3; y++) {
            if (mini >= price[x][y]) mini = price[x][y];
        }
    }
    cout << mini;
    return 0;
}