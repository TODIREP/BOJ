#include <iostream>
using namespace std;

int MIN = -1000000000;
int prefix[100002][2];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N, num, res = MIN;
    cin >> N;
    prefix[0][0] = MIN;
    for (int i = 1; i <= N; i++) {
        cin >> num;
        prefix[i][0] = max(prefix[i - 1][0], 0) + num;
        prefix[i][1] = max(prefix[i - 1][0], prefix[i - 1][1] + num);
        res = max(res, max(prefix[i][0], prefix[i][1]));
    }
    cout << res;
    return 0;
}