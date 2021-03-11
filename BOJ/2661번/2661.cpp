#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string ans;

bool search(string cur)
{
    if (cur.size() == N)
    {
        ans = cur;
        return true;
    }

    for (int i = 1; i <= 3; i++)
    {
        string nxt = cur + to_string(i);
        bool valid = false;
        for (int j = 1; j <= nxt.size() / 2; j++)
        {
            int start = nxt.size() - j;
            string tmp = nxt.substr(start, j);
            string cmp = nxt.substr(start - j, j);

            if (cmp.compare(tmp) == 0) valid = true;
        }
        if (valid) continue;
        if (search(nxt)) return true;
    }

    return false;
}

int main(void)
{
    cin >> N;
    search("");
    cout << ans;
    return 0;
}