#include <iostream>
#include <queue>
using namespace std;
typedef long long lint;

int main(void) {
    lint N, M, num;
    cin >> N >> M;

    priority_queue<pair<lint, lint>, vector<pair<lint, lint> >, greater<pair<lint, lint> > > q;
    for (int i = 0; i < N; i++) {
        cin >> num;
        q.push({num, num});
    }

    lint time;
    while (M--) {
        auto cur = q.top();q.pop();
        time = cur.first;
        q.push({time + cur.second, cur.second});
    }
    cout << time;
    return 0;
}