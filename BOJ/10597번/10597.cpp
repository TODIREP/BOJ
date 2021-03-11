#include <iostream>
#include <string>
#include <vector>
using namespace std;

int max_num = 0;
bool check[51];
string target;
vector<int> res;

bool search(int cur)
{
    if (cur >= target.size())
    {
        for (int i = 1; i <= max_num; i++)
        {
            if (!check[i]) return false;
        }
        return true;
    }

    for (int nxt = 1; nxt <= 2; nxt++)
    {
        int current = stoi(target.substr(cur, nxt));
        if (check[current] || current == 0) continue;
        
        check[current] = true;
        res.push_back(current);
        if (search(cur + nxt)) return true;
        check[current] = false;
        res.pop_back();
    }
    return false;
}

int main(void)
{
    cin >> target;
    int len = target.size();
    
    if (len > 9)
    {
        max_num = 9 + (len - 9) / 2;
    }
    else
    {
        max_num = len;
    }
    
    search(0);

    for (int r : res)
    {
        cout << r << ' ';
    }
    return 0;
}