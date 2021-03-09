#include <iostream>
#include <vector>
using namespace std;

int N, M, dis = 1000000000;
vector<pair<int, int>> home, chicken;
vector<bool> save;

void search(int start, int count)
{
    if (count == M)
    {
        int cur_dis = 0;

        for (int index = 0; index < home.size(); index++)
        {
            int min_dis = 1000000000;

            for (int c = 0; c < chicken.size(); c++)
            {
                if (!save[c]) continue;
                int distance = abs(home[index].first - chicken[c].first) + abs(home[index].second - chicken[c].second);
                min_dis = min(min_dis, distance);
            }

            cur_dis += min_dis;
        }

        dis = min(dis, cur_dis);
        return;
    }

    for (int index = start; index < chicken.size(); index++)
    {
        if (save[index]) continue;
        save[index] = true;
        search(index + 1, count + 1);
        save[index] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    int num;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            cin >> num;

            if (num == 1)
            {
                home.push_back({x, y});
            }
            else if (num == 2)
            {
                chicken.push_back({x, y});
                save.push_back(false);
            }
        }
    }

    search(0, 0);

    cout << dis;

    return 0;
}