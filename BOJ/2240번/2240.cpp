#include <iostream>
using namespace std;

int jadu[1001][32];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, W, input;
    cin >> T >> W;
    for (int index = 0; index < T; index++) {
        cin >> input;
        if (index == 0) {
            jadu[index][input - 1] = 1;
            continue;
        }

        if (input == 1) {
            for (int j = 1; j <= W; j += 2) jadu[index][j] = jadu[index - 1][j];
            for (int j = 0; j <= W; j += 2) {
                if (j == 0) jadu[index][j] = jadu[index - 1][j] + 1;
                else {
                    if (jadu[index - 1][j - 1] > 0) {
                        jadu[index][j] = max(jadu[index - 1][j], jadu[index - 1][j - 1]) + 1;
                    } else if (jadu[index - 1][j] > 0) jadu[index][j] = jadu[index - 1][j] + 1;
                }
            }
        } else {
            for (int j = 0; j <= W; j += 2) jadu[index][j] = jadu[index - 1][j];
            for (int j = 1; j <= W; j += 2) {
                if (j == 1) jadu[index][j] = jadu[index - 1][j] + 1;
                if (jadu[index - 1][j - 1] > 0) {
                    jadu[index][j] = max(jadu[index - 1][j], jadu[index - 1][j - 1]) + 1;
                } else if (jadu[index - 1][j] > 0) jadu[index][j] = jadu[index - 1][j] + 1;
            }
        }
    }

    int result = -1;
    for (int j = 0; j <= W; j++) result = max(result, jadu[T - 1][j]);
    cout << result;
    return 0;
}