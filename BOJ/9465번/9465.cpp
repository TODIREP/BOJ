#include <iostream>
using namespace std;

int arr[2][100001];
int score[2][100001];
int max(int a, int b) {
    return a > b ? a : b;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, N;
    cin >> T;
    while(T--) {
        int result = -1;
        cin >> N;
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < N; y++) {
                cin >> arr[x][y];
            }
        }
        score[0][0] = arr[0][0];
        score[1][0] = arr[1][0];

        for (int y = 1; y < N; y++) {
            for (int x = 0; x < 2; x++) {
                int sum;
                for (int q = 0; q < 2; q++) {
                    if (q == x) continue;
                    if (y == 1) sum = score[q][y - 1];
                    else sum = max(score[q][y - 1], score[q][y - 2]); 
                }
                score[x][y] = arr[x][y] + sum;
                result = max(result, score[x][y]);
            }
        }
        cout << result << "\n";
    }
    return 0;
}