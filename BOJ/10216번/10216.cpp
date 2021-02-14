#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct multi {
    int X, Y, R;
};
int find_root(vector<int> &r, int n) {
    if (r[n] < 0) return n;
    return r[n] = find_root(r, r[n]);
}
void union_root(vector<int> &r, int a, int b) {
    a = find_root(r, a);
    b = find_root(r, b);
    if (a == b) return;
    r[b] = a;
}
bool is_group(multi A, multi B) {
    return pow(A.R + B.R, 2) >= pow(A.X - B.X, 2) + pow(A.Y - B.Y, 2);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> root(N + 2, -1);
        vector<multi> node(N + 2);

        int X, Y, R;
        for (int i = 1; i <= N; i++) {
            cin >> X >> Y >> R;
            node[i] = {X, Y, R};
        }
        
        for (int p = 1; p <= N; p++) {
            for (int i = p + 1; i <= N; i++) {
                if (!is_group(node[i], node[p])) continue;
                union_root(root, i, p);
            }
        }
        int res = 0;
        for (int i = 1; i <= N; i++) if (root[i] == -1) res++;
        cout << res << "\n";
    }
    return 0;
}