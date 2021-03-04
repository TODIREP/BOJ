#include <iostream>
#include <vector>
using namespace std;

int N, stat[21][21], answer = 10000000;
bool people[21];

int get_sum(vector<int> &target)
{
    int sum = 0;

    for (int x = 0; x < target.size(); x++)
    {
        for (int y = 0; y < target.size(); y++)
        {
            if (x == y) continue;
            sum += stat[target[x]][target[y]];
        }
    }

    return sum;
}

void res()
{
    vector<int> start, link;

    for (int i = 0; i < N; i++)
    {
        if (people[i]) start.push_back(i);
        else link.push_back(i);
    }

    answer = min(answer, abs(get_sum(start) - get_sum(link)));
}

void search(int index, int count)
{
    if (count >= 2)
    {
        res();
    }
    if (count * 2 == N) return;

    for (int x = index; x < N; x++)
    {
        people[x] = true;
        search(x + 1, count + 1);
        people[x] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            cin >> stat[x][y];
        }
    }

    search(0, 0);
    cout << answer;
    return 0;
}