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
int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, M, K, A, B;
    cin >> N >> M;
    root.assign(N + 2, -1);
    while (M--) {
        cin >> K >> A >> B;
        if (K == 0) union_root(A, B);
        else cout << (find_root(A) == find_root(B) ? "YES" : "NO") << "\n";
    }
    for (int i = 0; i <= N; i++) cout << root[i] << " ";
    return 0;
}