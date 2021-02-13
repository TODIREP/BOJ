#include <iostream>
#include <vector>
using namespace std;

vector<int> root;
int find_root(int n) {return (root[n] < 0) ? n : (root[n] = find_root(root[n]));}
void union_root(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) return;
    root[a] += root[b];
    root[b] = a;
}

bool is_valid(int len) {
    int num;
    cin >> num;
    int root = find_root(num);
    while (--len) {
        cin >> num;
        if (root != find_root(num)) return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N, M, num;
    cin >> N >> M;
    root.assign(N + 2, -1);

    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            cin >> num;
            if (num) union_root(x, y);
        }
    }
    cout << (is_valid(M) ? "YES" : "NO");
    return 0;
}