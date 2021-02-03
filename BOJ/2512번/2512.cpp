#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int tax[10001];
int main(void) {
    fastio;
    int N, M, min_tax = 1000000001, max_tax = 2, res_tax, res_sum = 0;
    cin >> N;
    for (int index = 0; index < N; index++) {
        cin >> tax[index];
        min_tax = min(min_tax, tax[index]);
        max_tax = max(max_tax, tax[index]);
    }
    cin >> M;
    int left = 0, right = max_tax;
    while (left <= right) {
        int mid = (left + right) / 2;

        int temp_sum = 0;
        for (int index = 0; index < N; index++) {
            if (tax[index] > mid) temp_sum += mid;
            else temp_sum += tax[index];
        }

        if (temp_sum <= M) {
            if (temp_sum > res_sum) {
                res_sum = temp_sum;
                res_tax = mid;
            }
            left = mid + 1;
        } else right = mid - 1;
    }
    cout << res_tax;
    return 0;
}