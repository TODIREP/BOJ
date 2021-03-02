#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> nxt(K);
    for (int i = 0; i < K; i++)
    {
        cin >> nxt[i];
    }
    vector<int> plug(N);
    int start = 1;
    
    plug[0] = nxt[0];
    while (start < N)
    {
        for (int i = start; i < K; i++)
        {
            bool contain = false;
            for (int j = start - 1; j >= 0; j--)
            {
                if (nxt[i] == plug[j])
                {
                    contain = true;
                }
            }
            if (contain) continue;
            plug[start++] = nxt[i];
            break;
        }
    }

    int answer = 0;
    for (int i = start; i < K; i++)
    {
        bool contain = false;
        for (int j = N - 1; j >= 0; j--)
        {
            if (plug[j] == nxt[i])
            {
                contain = true;
                break;
            }
        }
        if (contain) continue;

        vector<int> dis(N, 1000);
        for (int p = 0; p < N; p++)
        {
            for (int j = i + 1; j < K; j++)
            {
                if (plug[p] == nxt[j])
                {
                    dis[p] = j;
                    break;
                }
            }
        }

        int change = -1, dis_max = 0;
        for (int p = 0; p < N; p++)
        {
            if (dis[p] > dis_max)
            {
                dis_max = dis[p];
                change = p;
            }
        }

        answer++;
        plug[change] = nxt[i];
    }

    cout << answer;
    return 0;
}