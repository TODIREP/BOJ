#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, input, answer = 0;
    cin >> N;
    vector<vector<int>> tree;
    stack<int> search;
    tree.resize(N);
    for (int index = 0; index < N; index++) {
        cin >> input;
        if (input == -1) search.push(index);
        else tree[input].push_back(index);
    }
    cin >> input;

    while(!search.empty()) {
        int cur = search.top();
        search.pop();

        if (cur == input) continue;
        int length = tree[cur].size();
        if (length == 0) {
            answer++;
            continue;
        }
        for (int index = 0; index < length; index++) {
            if (tree[cur][index] == input) {
                if (length == 1) answer++;
                continue;
            }
            search.push(tree[cur][index]);
        }
    }
    cout << answer;
    return 0;
}