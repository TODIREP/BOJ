#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[101];
int line[101];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, result = 0;
    cin >> N;
    for (int index = 0; index < N; index++) cin >> arr[index].first >> arr[index].second;
    sort(arr, arr + N);
    line[0] = 1;
    for (int index = 1; index < N; index++) {
        int front = 0;
        for (int cp = index - 1; cp >= 0; cp--) if (arr[cp].second < arr[index].second) front = max(front, line[cp]);
        line[index] = front + 1;
    }
    for (int index = 0; index < N; index++) result = max(result, line[index]);
    cout << N - result;
    return 0;
}