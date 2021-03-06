#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    long long num;
    vector<long long> big, small;

    for (int i = 0; i < N; i++)
    {
        cin >> num;

        if (num > 0) big.push_back(num);
        else small.push_back(num);
    }

    sort(big.begin(), big.end(), greater<long long>());
    sort(small.begin(), small.end(), less<long long>());
    
    long long sum = 0;

    for (int i = 0; i < big.size(); i++)
    {
        if (i + 1 == big.size() || big[i + 1] == 1)
        {
            sum += big[i];
        }
        else
        {
            sum += big[i] * big[++i];
        }
    }

    for (int i = 0; i < small.size(); i++)
    {
        if (i + 1 == small.size())
        {
            sum += small[i];
        }
        else
        {
            sum += small[i] * small[++i];
        }
    }

    cout << sum;
    return 0;
}