#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define endl "\n"
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

string A[500001], res[500001];
int main(void) {
    fastio;
    int N, M, result = 0;
    string input;
    cin >> N >> M;
    for (int index = 0; index < N; index++) cin >> A[index];
    sort(A, A + N);
    for (int index = 0; index < M; index++) {
        cin >> input;

        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int check = input.compare(A[mid]);
            if (check < 0) right = mid - 1;
            else if (check > 0) left = mid + 1;
            else {
                res[result++] = input;
                break;
            }
        }
    }
    cout << result << endl;
    sort(res, res + result);
    if (result > 0) for (int index = 0; index < result; index++) cout << res[index] << endl;
    return 0;
}