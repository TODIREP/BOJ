#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int arr[100001];
int main(void) {
    fastio;
    int N, S;
    cin >> N >> S;
    for (int index = 0; index < N; index++) cin >> arr[index];
    int start = 0, end = 0, sum, cur_size, ans = -1;

    sum = arr[0];
    cur_size = 1;
    while (end < N) {
        if (sum >= S) {
            if (ans == -1) ans = cur_size;
            else ans = min(ans, cur_size);
            cur_size--;
            sum -= arr[start++];
        } else if (sum < S) {
            cur_size++;
            sum += arr[++end];
        }
        if (start > end) {
            cur_size++;
            sum += arr[++end];
        }
    }
    cout << ((ans == -1) ? 0 : ans);
    return 0;
}