#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr;
    int N, X, answer = 0, e;
    cin >> N;
    arr.resize(N);
    for (int index = 0; index < N; index++) {
        cin >> arr[index];
    }
    cin >> X;
    sort(arr.begin(), arr.end());

    for (int index = 0; index < N - 1;) {
        int temp = arr[index] + arr[N - 1];
        if (temp > X) N--;
        else {
            if (temp == X) answer++;
            index++;
        }
    }
    cout << answer;
    return 0;
}