#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int arr[10001];
int main(void) {
    fastio;
    int N, M, res = 0, sum = 0;
    cin >> N >> M;
    for (int index = 0; index < N; index++) cin >> arr[index];
    int A = 0, B = 0;
    sum = arr[0];
    while (A < N && B < N) {
        if (sum == M) {
            res++;
            sum -= arr[A++];
        } else if (sum < M) sum += arr[++B];
        else sum -= arr[A++];
        if (A > B) sum += arr[++B];
    }
    cout << res;
    return 0;
}