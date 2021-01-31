#include <iostream>
using namespace std;
#define endl "\n"
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int res[100001];
int main(void) {
    fastio;
    int N, M, i, j;
    cin >> N;
    for (int index = 1; index <= N; index++) {
        cin >> res[index];
        res[index] += res[index - 1];
    }
    cin >> M;

    while (M--) {
        cin >> i >> j;
        cout << res[j] - res[i - 1] << endl;
    }
    return 0;
}