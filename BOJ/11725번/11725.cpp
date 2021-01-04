#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> target;
vector<int> root;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, a, b;
    cin >> N;
    target.resize(N);
    root.assign(N + 1, 0);
    queue<int> Q;

    for (int index = 1; index < N; index++) {
        cin >> a >> b;
        target[a - 1].push_back(b);
        target[b - 1].push_back(a);
    }
    
    for (int index = 0; index < N; index++) {
        for (int index2 = 0; index2 < target[index].size(); index2++) {
            if (root[target[index][index2]] == 0) {
                root[target[index][index2]] = index + 1;
                Q.push(target[index][index2]);
                while (!Q.empty()) {
                    int cur = Q.front();
                    Q.pop();

                    for (int index3 = 0; index3 < target[cur - 1].size(); index3++) {
                        if (root[target[cur - 1][index3]] != 0) continue; 
                        root[target[cur - 1][index3]] = cur;
                        Q.push(target[cur - 1][index3]);
                    }
                }
            }
        }
    }
    for (int index = 2; index < N + 1; index++) {
        cout << root[index] << "\n";
    }
    return 0;
}