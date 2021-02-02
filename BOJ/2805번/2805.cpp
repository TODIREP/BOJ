#include <iostream>
using namespace std;
#define lint long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

lint tree[1000002];
int main(void) {
    fastio;
    lint N, M, M_tree = 0, answer = 0;
    cin >> N >> M;

    for (int index = 0; index < N; index++) {
        cin >> tree[index];
        M_tree = max(M_tree, tree[index]);
    }

    lint m_tree = 0;
    while (m_tree <= M_tree) {
        lint cut_tree = (m_tree + M_tree) / 2;

        lint res = 0;
        for (int index = 0; index < N; index++) {
            if (tree[index] <= cut_tree) continue;
            lint cut = tree[index] - cut_tree;
            res += cut;
            if (res > M) break;
        }

        if (res >= M) {
            answer = max(answer, cut_tree);
            m_tree = cut_tree + 1;
        }
        else M_tree = cut_tree - 1;
    }
    cout << answer;
    return 0;
}