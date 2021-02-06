#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T, N, M, input;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        vector<int> A(N), B(M);
        for (int index = 0; index < N; index++) cin >> A[index];
        for (int index = 0; index < M; index++) cin >> B[index];
        sort(B.begin(), B.end());
        
        int res = 0;
        for (int index = 0; index < N; index++)
            res += lower_bound(B.begin(), B.end(), A[index]) - B.begin();
        cout << res << "\n";
    }
    return 0;
}