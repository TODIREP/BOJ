#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MIN -1e9 - 1
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, result;
    vector<int> arr, sum;
    cin >> N;
    arr.resize(N);
    sum.resize(N);
    sum[0] = MIN;

    for (int index = 0; index < N; index++) {
        cin >> arr[index];
    }
    result = arr[0];
    for (int index = 1; index < N; index++) {
        sum[index] = max(sum[index - 1], arr[index - 1]) + arr[index];
        sum[index] = max(sum[index], arr[index]);
        result = max(result, sum[index]);
    }
    cout << result;
    return 0;
}