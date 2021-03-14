#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node
{
    int link, dis;
    bool operator<(const node &a) const
    {
        return dis > a.dis;
    }
};
vector<node> road[1001];
priority_queue<int> max_heap[1001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    int A, B, C;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        road[A].push_back({B, C});
    }

    priority_queue<node> min_heap;
    min_heap.push({1, 0});
    max_heap[1].push(0);

    while (!min_heap.empty())
    {
        auto cur = min_heap.top();
        min_heap.pop();

        for (auto nxt : road[cur.link])
        {
            int nxt_node = nxt.link;
            int nxt_dis = cur.dis + nxt.dis;

            if (max_heap[nxt_node].size() < K)
            {
                max_heap[nxt_node].push(nxt_dis);
                min_heap.push({nxt_node, nxt_dis});
            }
            else 
            {
                if (max_heap[nxt_node].top() > nxt_dis)
                {
                    max_heap[nxt_node].pop();
                    max_heap[nxt_node].push(nxt_dis);
                    min_heap.push({nxt_node, nxt_dis});
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (max_heap[i].size() != K)
        {
            cout << -1;
        }
        else
        {
            cout << max_heap[i].top();
        }
        cout << '\n';
    }

    return 0;
}