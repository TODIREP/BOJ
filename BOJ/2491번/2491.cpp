#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int arr[100001], res[100001][2];
int main(void) {
    fastio();
    int N, ans = 1;
    cin >> N;
    for (int index = 0; index < N; index++) cin >> arr[index];
    res[0][0] = res[0][1] = 1;
    for (int index = 1; index < N; index++) {
        if (arr[index - 1] <= arr[index]) res[index][0] = res[index - 1][0] + 1;
        else res[index][0] = 1;
        if (arr[index - 1] >= arr[index]) res[index][1] = res[index - 1][1] + 1;
        else res[index][1] = 1;
        ans = max(ans, max(res[index][0], res[index][1]));
    }
    cout << ans;
    return 0;
}