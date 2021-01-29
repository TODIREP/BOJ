#include <iostream>
#include <queue>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, input;
    priority_queue<int, vector<int>, greater<int> > q;
    cin >> N;

    for (int index = 0; index < N; index++) {
        cin >> input;
        q.push(input);
    }
    for (int index = 1; index < N; index++) {
        for (int num = 0; num < N; num++) {
            cin >> input;
            if (input > q.top()) {
                q.pop();
                q.push(input);
            }
        }
    }
    cout << q.top();
    return 0;
}