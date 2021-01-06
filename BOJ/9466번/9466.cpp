#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, N, input, answer;
    cin >> T;
    while (T--) {
        vector<int> teams;
        vector<bool> visit, res;
        queue<int> q;
        stack<int> stk;
        cin >> N;
        teams.resize(N + 1);
        visit.assign(N + 1, false);
        res.assign(N + 1, false);
        answer = 0;

        for (int index = 1; index <= N; index++) {
            cin >> teams[index];
        }

        for (int index = 1; index <= N; index++) {
            if (!visit[index]) {
                q.push(index);
                stk.push(index);
                visit[index] = true;

                while(!stk.empty()) {
                    int cur = stk.top();
                    stk.pop();

                    if (visit[teams[cur]]) {
                        while (!q.empty() && teams[cur] != q.front()) {
                            q.pop();
                        }

                        while (!q.empty()) {
                            res[q.front()] = true;
                            q.pop();
                        }
                        continue;
                    }
                    q.push(teams[cur]);
                    stk.push(teams[cur]);
                    visit[teams[cur]] = true;
                }
            }
        }

        for (int index = 1; index <= N; index++) {
            if (!res[index]) {
                answer++;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}