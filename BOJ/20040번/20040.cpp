#include <iostream>
#include <vector>
using namespace std;

vector<int> root;
int find_root(int n) {return ((root[n] < 0) ? n : (root[n] = find_root(root[n])));}
int union_root(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) return -1;
    root[a] += root[b];
    root[b] = a;
    return root[a] * -1;
}
int solution() {
    int N, M, ans = 0;
    cin >> N >> M;
    root.assign(N + 2, -1);

    int a, b;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        if (union_root(a, b) == -1 && ans == 0) ans = i;
    }
    return ans;
}

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout << solution();
    return 0;
}