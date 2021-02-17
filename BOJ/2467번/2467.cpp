#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int N, vector<int> &arr) {
    vector<int> ans(2, 0);
    int sum = 2000000001;
    for (int i = 0; i < N; i++) {
        int left = i + 1, right = N - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (abs(arr[i] + arr[mid]) < sum) {
                sum = abs(arr[i] + arr[mid]);
                if (arr[i] < arr[mid]) {
                    ans[0] = arr[i];
                    ans[1] = arr[mid];
                } else {
                    ans[1] = arr[i];
                    arr[0] = arr[mid];
                }
            }
            if (sum == 0) return ans;
            if (arr[i] + arr[mid] < 0) left = mid + 1;
            else right = mid - 1;
        }
    }
    return ans;
}

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N;
    cin >> N;

    vector<int> item(N);
    for (int i = 0; i < N; i++) cin >> item[i];

    vector<int> ans = solution(N, item);
    cout << ans[0] << " " << ans[1];
    return 0;
}