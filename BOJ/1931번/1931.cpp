#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int> > meeting(N);

    for (int i = 0; i < N; i++)
    {
        cin >> meeting[i].first >> meeting[i].second;
    }

    sort(meeting.begin(), meeting.end(), cmp);

    int count = 1, before = meeting[0].second;

    for (int i = 1; i < N; i++)
    {
        if (meeting[i].first < before) continue;
        count++;
        before = meeting[i].second;
    }

    cout << count;
    
    return 0;
}