// 시간복잡도 (최악 / 최선 / 평균)
// 모두 n log n
// 공간복잡도 n

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
void sorted(vector<int> &target, int start, int finish, int mid) {
    vector<int> res;
    int front = start, back = mid + 1, copy = 0;

    while (front <= mid && back <= finish) {
        if (target[front] < target[back]) res.push_back(target[front++]);
        else if (target[front] > target[back]) res.push_back(target[back++]);
        else {
            res.push_back(target[front++]);
            res.push_back(target[back++]);
        }
    }
    while (front <= mid) res.push_back(target[front++]);
    while (back <= finish) res.push_back(target[back++]);
    for (int index = start; index <= finish; index++) target[index] = res[copy++];
}

void sorting(vector<int> &target, int start, int finish) {
    if (start < finish) {
        int mid = (start + finish) / 2;
        sorting(target, start, mid);
        sorting(target, mid + 1, finish);
        sorted(target, start, finish, mid);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    arr.resize(N);
    for (int index = 0; index < N; index++) cin >> arr[index];
    sorting(arr, 0, N - 1);
    for (int index = 0; index < N; index++) cout << arr[index] << "\n";
    return 0;
}