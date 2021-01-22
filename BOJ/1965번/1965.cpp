#include <iostream>
using namespace std;
#define plus(a, b) (a + b)
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int box[1001], result[1001];
int main(void) {
    fastio()
    int N, ans = 0;
    cin >> N;
    result[0] = 1;
    for (int index = 0; index < N; index++) cin >> box[index];
    for (int cur = 0; cur < N; cur++) {
        int temp = 0;
        for (int next = cur - 1; next >= 0; next--) {
            if (box[next] < box[cur]) temp = max(temp, result[next]);
        }
        result[cur] = temp + 1;
        ans = max(ans, result[cur]);
    }
    cout << ans;
    return 0;
}