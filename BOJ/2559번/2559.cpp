#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int arr[100002];
int main(void) {
    fastio;
    int N, K, res;
    cin >> N >> K;
    for (int index = 0; index < N; index++) cin >> arr[index];
    int start = 0, end, temp = 0;
    for (end = 0; end < K; end++) temp += arr[end];
    end--;
    res = temp;
    while (end < N) {
        res = max(res, temp);
        temp -= arr[start++];
        temp += arr[++end];
    }
    cout << res;
    return 0;
}