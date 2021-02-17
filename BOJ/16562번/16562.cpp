#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> root, money;
int find_root(int n) {
    if (root[n] < 0) return n;
    return root[n] = find_root(root[n]);
}
bool union_root(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) return false;

    if (money[a] <= money[b]) root[b] = a;
    else root[a] = b;

    return true;
}

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, M, K;
    cin >> N >> M >> K;

    root.assign(N + 1, -1);
    money.resize(N + 1);

    for (int i = 1; i <= N; i++) cin >> money[i];

    int V, W;
    while (M--) {
        cin >> V >> W;
        bool res = union_root(V, W);
    }

    int target = 0;
    vector<pair<int, int> > connect;
    for (int i = 1; i <= N; i++) {
        if (root[i] == -1) {
            target++;
            connect.push_back({money[i], i});
        }
    }
    sort(connect.begin(), connect.end());

    int sum = 0;
    for (int i = 0; i < target; i++) {
        if (!union_root(connect[i].second, 0)) continue;
        sum += connect[i].first;
    }

    if (sum <= K) cout << sum;
    else cout << "Oh no";
    return 0;
}