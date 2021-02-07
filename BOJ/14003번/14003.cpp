#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int NUM[1000001], LIS[1000001], PRE[1000001];
int STK[1000001], STK_PRE[1000001];
int lower_index(int right, int target) {
    int left = 0;
    while (left < right) {
        int mid = (left + right) / 2;
        if (STK[mid] >= target) right = mid;
        else left = mid + 1;
    }
    return left;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int N, pos = 1;
    cin >> N;
    STK[0] = -1000000002;

    for (int I = 1; I <= N; I++) {
        cin >> NUM[I];
        int target = lower_index(pos, NUM[I]);
        pos += (target == pos);
        
        STK[target] = NUM[I];
        STK_PRE[target] = I;
        LIS[I] = target;
        PRE[I] = STK_PRE[target - 1];
    }

    int result = 0;
    for (int I = 1; I <= N; I++) {
        if (result < LIS[I]) {
            result = LIS[I];
            pos = I;
        }
    }

    stack<int> res;
    while (pos != 0) {
        res.push(NUM[pos]);
        pos = PRE[pos];
    }
    cout << result << "\n";
    while (!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }
    return 0;
}