#include <iostream>
#include <string>
using namespace std;

string str[1002][1002];
int count[1002][1002];

string longer(string a, string b) {
    return a.size() > b.size() ? a : b;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string A, B, res;
    int result = 0;
    cin >> A >> B;

    for (int x = 0; A[x] != '\0'; x++) {
        for (int y = 0; B[y] != '\0'; y++) {
            if (x == 0 && y == 0) {
                count[x][y] = A[x] == B[y];
                if (count[x][y]) str[x][y] = A[x];
            }
            else {
                if (A[x] == B[y]) {
                    if (x == 0 || y == 0) {
                        count[x][y] = 1;
                        str[x][y] = A[x];
                    } else {
                        count[x][y] = min(count[x - 1][y - 1], min(count[x - 1][y], count[x][y - 1])) + 1;
                        string temp = str[x - 1][y - 1] + A[x];
                        str[x][y] = str[x - 1][y - 1] + A[x];
                    }
                } else {
                    if (x == 0) {
                        count[x][y] = count[x][y - 1];
                        str[x][y] = str[x][y - 1];
                    } else if (y == 0) {
                        count[x][y] = count[x - 1][y];
                        str[x][y] = str[x - 1][y];
                    } else {
                        count[x][y] = max(count[x - 1][y - 1], max(count[x - 1][y], count[x][y - 1]));
                        str[x][y] = longer(str[x - 1][y - 1], longer(str[x - 1][y], str[x][y - 1]));
                    }
                }
            }
            if (count[x][y] > result) {
                result = count[x][y];
                res = str[x][y];
            }
        }
    }
    cout << result << "\n" << res;
    return 0;
}
