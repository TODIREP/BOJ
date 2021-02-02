#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int N, arr[500001];

int lower_index(int target) {
    int left = 0, right = N;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= target) right = mid;
        else left = mid + 1;
    }
    return left;
}

int upper_index(int target) {
    int left = 0, right = N;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] > target) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main(void) {
    fastio;
    int M, target;
    cin >> N;
    for (int index = 0; index < N; index++) cin >> arr[index];
    sort(arr, arr + N);
    cin >> M;
    for (int index = 0; index < M; index++) {
        cin >> target;
        // 이분 탐색으로 구현
        cout << upper_index(target) - lower_index(target) << " ";
        // STL 이분 탐색
        cout << upper_bound(arr, arr + N, target) - lower_bound(arr, arr + N, target) << " ";
    }
    return 0;
}