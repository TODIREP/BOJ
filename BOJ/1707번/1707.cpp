#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check(vector<vector<int> > &link)
{
    vector<int> color(link.size(), 0);
    queue<int> q;

    for (auto S : link)
    {
        for (auto N : S)
        {
            if (color[N] > 0) continue;
            color[N] = 1;
            q.push(N);

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                int nxt_color = color[cur] + 1;
                if (nxt_color > 2) nxt_color = 1;

                for (auto nxt : link[cur])
                {
                    if (color[nxt] == color[cur]) return false;
                    if (color[nxt] == nxt_color) continue;
                    color[nxt] = nxt_color;
                    q.push(nxt);
                }
            }
        }
    }
    
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int> > node(V + 1);
        int A, B;
        for (int i = 0; i < E; i++)
        {
            cin >> A >> B;
            node[A].push_back(B);
            node[B].push_back(A);
        }

        cout << (check(node) ? "YES" : "NO") << '\n';
    }
    return 0;
}