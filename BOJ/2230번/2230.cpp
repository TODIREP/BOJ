#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int arr[100001];
int abs(int a) { return a > 0 ? a : a * -1;}
int main(void) {
    fastio;
    int N, M;
    cin >> N >> M;
    for (int index = 0; index < N; index++) cin >> arr[index];
    sort(arr, arr + N);
    int start = 0, end = 0, diff = 0, res = 2000000001;
    while (end < N) {
        diff = abs(arr[start] - arr[end]);
        if (diff < M) end++;
        else {
            res = min(res, diff);
            start++;
        }
        if (start > end) end++;
    }
    cout << res;
    return 0;
}