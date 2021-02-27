#include <iostream>
#include <queue>
#include <set>
using namespace std;
using lint = long long;

lint LIMITS = (1LL << 31);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lint K, N, input[101], LIM = 0;
    cin >> K >> N;

    priority_queue<int, vector<int>, greater<int> > q;
    set<int> st;

    for (lint i = 0; i < K; i++)
    {
        cin >> input[i];
        LIM = max(LIM, input[i]);
        st.insert(input[i]);
        q.push(input[i]);
    }

    lint cnt = 0;
    while (!q.empty())
    {
        auto cur = q.top();
        q.pop();

        cnt++;
        if (cnt == N)
        {
            cout << cur;
            return 0;
        }

        for (lint i = 0; i < K; i++)
        {
            lint nxt = cur * input[i];
            if (nxt >= LIMITS || st.count(nxt) == 1) continue;
            if (q.size() > N && nxt > LIM) continue;

            st.insert(nxt);
            q.push(nxt);
            LIM = max(LIM, nxt);
        }
    }
}