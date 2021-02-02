#include <iostream>
#include <algorithm>
using namespace std;
#define endl "\n"
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int arr[100001];
int main(void) {
    fastio;
    int N, M, target;
    cin >> N;
    for (int index = 0; index < N; index++) cin >> arr[index];
    sort(arr, arr + N);
    cin >> M;
    for (int index = 0; index < M; index++) {
        cin >> target;

        int left = 0, right = N - 1;
        bool found = false;
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (arr[mid] == target) {
                found = true;
                break;
            } else if (arr[mid] > target) right = mid - 1;
            else left = mid + 1;
        }

        cout << found << endl;
    }
    return 0;
}