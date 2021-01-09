#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    vector<int> arr;
    cin >> N;
    arr.assign(N + 1, 1000000);

    arr[1] = 0;
    for (int index = 1; index <= N; index++) {
        if (index + 1 <= N && arr[index] + 1 <= arr[index + 1]) arr[index + 1] = arr[index] + 1;
        if (index * 2 <= N && arr[index] + 1 <= arr[index * 2]) arr[index * 2] = arr[index] + 1;
        if (index * 3 <= N && arr[index] + 1 <= arr[index * 3]) arr[index * 3] = arr[index] + 1;
    }
    cout << arr[N];
    return 0;
}