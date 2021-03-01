#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > point;

int pow(int N)
{
    return N * N;
}

int get_distance(pair<int, int> a, pair<int, int> b)
{
    return pow(a.first - b.first) + pow(a.second - b.second);
}

int search(int S, int E)
{
    if (E - S <= 2)
    {
        int result = 1e9;
        for (int index = S; index <= E; index++)
        {
            for (int indexB = index + 1; indexB <= E; indexB++)
            {
                result = min(result, get_distance(point[index], point[indexB]));
            }
        }
        return result;
    }

    int mid = (S + E) / 2;
    int result = min(search(S, mid), search(mid + 1, E));
    int left = mid, right = mid;

    vector<pair<int, int> > check;
    check.push_back({point[mid].second, point[mid].first});
    for (int index = S; index <= E; index++)
    {
        if (index == mid) continue;
        if (pow(point[index].first - point[mid].first) >= result) continue;
        check.push_back({point[index].second, point[index].first});
    }
    sort(check.begin(), check.end());

    for (int A = 0; A < check.size(); A++)
    {
        for (int B = A + 1; B < check.size(); B++)
        {
            if (pow(check[A].first - check[B].first) >= result) break;
            pair<int, int> A_point = {check[A].second, check[A].first};
            pair<int, int> B_point = {check[B].second, check[B].first};
            result = min(result, get_distance(A_point, B_point));
        }
    }
    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    point.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> point[i].first >> point[i].second;
    }
    sort(point.begin(), point.end());

    cout << search(0, N - 1);
    return 0;
}