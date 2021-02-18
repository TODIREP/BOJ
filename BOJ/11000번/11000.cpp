#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> input[200001];
int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, S, T;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> input[i].first >> input[i].second;
    sort(input, input + N);
    priority_queue<int, vector<int>, greater<int> > q;

    for (int i = 0; i < N; i++) {
        S = input[i].first;
        T = input[i].second;
        if (!q.empty() && q.top() <= S) q.pop();
        q.push(T);
    }
    cout << q.size();
    return 0;
}