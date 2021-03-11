#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int A, B;
        cin >> A >> B;

        vector<int> pre(10001, -1);
        vector<char> oper(10001, 'K');

        queue<int> q;
        q.push(A);

        while (!q.empty())
        {
            int cur_num = q.front();
            q.pop();

            int next_num[4] = {cur_num * 2 % 10000,
                            (cur_num > 0 ? cur_num - 1 : 9999),
                            cur_num / 1000 + (cur_num % 1000) * 10,
                            (cur_num % 10) * 1000 + cur_num / 10};
            char opers[4] = {'D', 'S', 'L', 'R'};

            for (int nx = 0; nx < 4; nx++)
            {
                int nx_num = next_num[nx];
                if (oper[nx_num] != 'K') continue;
                
                pre[nx_num] = cur_num;
                oper[nx_num] = opers[nx];

                if (nx_num == B)
                {
                    vector<char> res;
                    while (nx_num != A)
                    {
                        res.push_back(oper[nx_num]);
                        nx_num = pre[nx_num];
                    }
                    for (int index = res.size() - 1; index >= 0; index--)
                    {
                        cout << res[index];
                    }
                    cout << '\n';

                    while(!q.empty()) q.pop();
                    break;
                }

                q.push(nx_num);
            }
        }
    }
    return 0;
}