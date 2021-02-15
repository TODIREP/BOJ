#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct link {
    int A, B, C;
    bool operator<(const link &a) const { return C < a.C; }
};

int find_root(vector<int> &r, int n) {
    if (r[n] < 0) return n;
    return r[n] = find_root(r, r[n]);
}

bool union_root(vector<int> &r, int a, int b) {
    a = find_root(r, a);
    b = find_root(r, b);
    if (a == b) return false;
    r[b] = a;
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    while (true) {
        int M, N, answer = 0;
        cin >> M >> N;
        if (M == 0 && N == 0) return 0;
        
        vector<int> root(M + 1, -1);
        vector<link> node;

        int X, Y, Z;
        while (N--) {
            cin >> X >> Y >> Z;
            answer += Z;
            node.push_back({X, Y, Z});
        }
        sort(node.begin(), node.end());

        for (auto item: node) {
            if (!union_root(root, item.A, item.B)) continue;
            answer -= item.C;
        }
        cout << answer << "\n";
    }
}