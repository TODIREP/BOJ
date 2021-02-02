#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl " "
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main(void) {
    fastio;
    int A, B;
    cin >> A >> B;
    vector<int> res, A_num(A), B_num(B);
    for (int index = 0; index < A; index++) cin >> A_num[index];
    for (int index = 0; index < B; index++) cin >> B_num[index];
    sort(B_num.begin(), B_num.end());
    for (int index = 0; index < A; index++) {
        int left = 0, right = B - 1;

        bool found = true;
        while (right - left > 3) {
            int mid = (left + right) / 2;
            if (B_num[mid] > A_num[index]) right = mid - 1;
            else if (B_num[mid] < A_num[index]) left = mid + 1;
            else {
                found = false;
                break;
            }
        }
        if (found) {
            for (int check = left; check <= right; check++) {
                if (B_num[check] == A_num[index]) {
                    found = false;
                    break;
                }
            }
        }
        if (found) res.push_back(A_num[index]);
    }
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (auto result: res) cout << result << endl;
    return 0;
}