#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, take, K, num, result = 0;
    cin >> N;
    vector<int> before(N + 1, 0), time(N + 1, 0), res(N + 1, 0);
    vector<vector<int> > nxt(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> take >> K;
        time[i] = take;

        while (K--) {
            cin >> num;
            nxt[num].push_back(i);
            before[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (before[i] == 0) {
            res[i] = time[i];
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto target: nxt[cur]) {
            res[target] = max(res[target], res[cur] + time[target]);
            if (--before[target] == 0) q.push(target);
        }
    }

    for (int i = 1; i <= N; i++) result = max(result, res[i]);
    cout << result;
    return 0;
}