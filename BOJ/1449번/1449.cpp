#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, L;
    cin >> N >> L;

    vector<int> water(N);

    for (int i = 0; i < N; i++)
    {
        cin >> water[i];
    }

    sort(water.begin(), water.end());

    int count = 1, nxt = water[0] + L - 1;

    for (int i = 0; i < N; i++)
    {
        if (water[i] <= nxt) continue;
        count++;
        nxt = water[i] + L - 1;
    }
    
    cout << count;
    return 0;
}