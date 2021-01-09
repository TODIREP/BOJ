#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int stair[302][3];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    vector<int> arr;
    cin >> N;
    arr.resize(N + 1);
    for (int index = 1; index <= N; index++) {
        cin >> arr[index];
    }
    stair[1][1] = arr[1];
    stair[2][1] = arr[2];
    stair[2][2] = arr[1] + arr[2];

    for (int index = 3; index <= N; index++) {
        stair[index][1] = max(stair[index - 2][1], stair[index - 2][2]) + arr[index];
        stair[index][2] = stair[index - 1][1] + arr[index];
    }
    cout << max(stair[N][1], stair[N][2]);
    return 0;
}