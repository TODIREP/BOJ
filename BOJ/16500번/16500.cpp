#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    string target;
    cin >> target;

    int N, target_len = target.size();
    cin >> N;

    vector<bool> valid(target_len + 1, false);
    vector<string> check(N);

    for (int i = 0; i < N; i++)
    {
        cin >> check[i];
    }

    valid[0] = true;
    for (int i = 1; i <= target_len; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i < check[j].size()) continue;
            int before = i - check[j].size();
            if (!valid[before]) continue;

            string temp = target.substr(before, check[j].size());

            if (temp.compare(check[j]) == 0)
            {
                valid[before + check[j].size()] = true;
            }
        }
    }
    
    cout << valid[target_len];
    return 0;
}