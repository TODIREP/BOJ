#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int LIMITS = 100001;
int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> dis(LIMITS + 1, 1000000);

    queue<int> q;
    dis[N] = 0;
    q.push(N);

    int res = 10000000, count = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == K) {
            if (dis[cur] == res) count++;
            else if (dis[cur] < res) {
                res = dis[cur];
                count = 1;
            }
            continue;
        }

        for (int nxt : {cur + 1, cur - 1, cur * 2}) {
            if (nxt < 0 || nxt > LIMITS) continue;
            if (dis[nxt] < dis[cur] + 1) continue;
            dis[nxt] = dis[cur] + 1;
            q.push(nxt);
        }
    }
    
    cout << res << "\n" << count;
    return 0;
}