#include <iostream>
#include <string>
using namespace std;

int count[4001][4001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string A, B;
    int result = 0;
    cin >> A >> B;

    for (int x = 0; A[x] != '\0'; x++) {
        for (int y = 0; B[y] != '\0'; y++) {
            if (A[x] == B[y]) {
                if (x == 0 || y == 0) count[x][y] = 1;
                else count[x][y] = count[x - 1][y - 1] + 1;
                result = max(result, count[x][y]);
            }
        }
    }
    cout << result;
    return 0;
}