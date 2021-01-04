#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> target;
vector<int> visit;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, a, b, answer = 0;
    cin >> N >> M;
    queue<int> Q;
    target.resize(N + 1);
    visit.assign(N + 1, 0);

    while(M--) {
        cin >> a >> b;
        target[a].push_back(b);
        target[b].push_back(a);
    }

    for (int index = 1; index <= N; index++) {
        if (visit[index] == 0) {
            visit[index] = 1;
            Q.push(index);
            answer++;
            while (!Q.empty()) {
                int cur = Q.front();
                Q.pop();
                
                for (int index2 = 0; index2 < target[cur].size(); index2++) {
                    if (visit[target[cur][index2]] != 0) continue;
                    visit[target[cur][index2]] = 1;
                    Q.push(target[cur][index2]);
                }
            }
        }
    }
    cout << answer;
    return 0;
}