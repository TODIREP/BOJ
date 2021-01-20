#include <iostream>
using namespace std;

int arr[1001][3], price[1001][3][3];

int mini(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? b : a;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, result = 1e9;
    cin >> N;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < 3; y++) {
            cin >> arr[x][y];
            price[x][y][y] = arr[x][y];
        }
    }

    for (int x = 1; x < N; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                int min = 1e9;
                for (int index = 0; index < 3; index++) {
                    if (index == y) continue;
                    min = mini(min, price[x - 1][index][z]);
                }
                price[x][y][z] = min + arr[x][y];
            }
        }
    }
    
    for (int y = 0; y < 3; y++) {
        for (int z = 0; z < 3; z++) {
            if (y == z) continue;
            result = min(result, price[N - 1][y][z]);
        }
    }
    cout << result;
    return 0;
}