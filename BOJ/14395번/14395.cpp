#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;
#define lint long long

int main(void)
{
    lint S, T, L = 1000000000;
    cin >> S >> T;

    set<lint> st;
    queue<pair<lint, string> > q;
    st.insert(S);
    q.push({S, ""});

    while (!q.empty())
    {
        lint N, C = q.front().first;
        string O = q.front().second;
        q.pop();

        if (C == T)
        {
            if (O.size() == 0) cout << 0;
            else cout << O;
            return 0;
        }

        N = C * C;
        if (N <= L and N > 0 and st.count(N) == 0)
        {
            st.insert(N);
            q.push({N, O + '*'});
        }

        N = C + C;
        if (N <= L and N > 0 and st.count(N) == 0)
        {
            st.insert(N);
            q.push({N, O + '+'});
        }

        N = 1;
        if (st.count(N) == 0)
        {
            st.insert(N);
            q.push({N, O + '/'});
        }
    }

    cout << -1;
    return 0;
}