#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, num;
    cin >> N;
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < N; i++) {
        cin >> num;
        q.push(num);
    }
    int sum = 0;
    while (q.size() >= 2) {
        int left = q.top();q.pop();
        int right = q.top();q.pop();
        sum += left + right;
        q.push(left + right);
    }
    cout << sum;
    return 0;
}