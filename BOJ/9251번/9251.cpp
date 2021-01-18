#include <iostream>
#include <string>
using namespace std;

int count[1002][1002];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string A, B;
    int result = 0;
    cin >> A >> B;

    for (int x = 0; A[x] != '\0'; x++) {
        for (int y = 0; B[y] != '\0'; y++) {
            if (x == 0 && y == 0) count[x][y] = A[x] == B[y];
            else {
                if (A[x] == B[y]) {
                    if (x == 0 || y == 0) count[x][y] = 1;
                    else count[x][y] = min(count[x - 1][y - 1], min(count[x - 1][y], count[x][y - 1])) + 1;
                } else {
                    if (x == 0) count[x][y] = count[x][y - 1];
                    else if (y == 0) count[x][y] = count[x - 1][y];
                    else count[x][y] = max(count[x - 1][y - 1], max(count[x - 1][y], count[x][y - 1]));
                }
            }
            result = max(result, count[x][y]);
        }
    }
    cout << result;
    return 0;
}
