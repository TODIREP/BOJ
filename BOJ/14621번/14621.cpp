#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool school[1001];
struct link
{
    int A, B, C;
    bool operator<(const link &a) const
    {
        return C < a.C;
    }
};
link input[10001];
int root[1001];
int find_root(int n)
{
    if (root[n] < 0) return n;
    return root[n] = find_root(root[n]);
}

bool union_root(int a, int b)
{
    if (school[a] == school[b]) return false;
    a = find_root(a);
    b = find_root(b);
    if (a == b) return false;
    root[b] = a;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    memset(root, -1, sizeof(root));
    cin >> N >> M;
    char value[2];

    for (int i = 1; i <= N; i++)
    {
        cin >> value;
        school[i] = (value[0] == 'M');
    }

    int U, V, D;
    for (int i = 0; i < M; i++)
    {
        cin >> U >> V >> D;
        input[i] = {U, V, D};
    }
    sort(input, input + M);

    int answer = 0;
    for (int i = 0; i < M; i++)
    {
        if (!union_root(input[i].A, input[i].B)) continue;
        answer += input[i].C;
    }
    
    int root_school = 0;
    for (int i = 1; i <= N; i++)
    {
        root_school += (root[i] < 0);
    }
    
    if (root_school == 1) cout << answer;
    else cout << -1;

    return 0;
}