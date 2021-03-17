#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

string num[10001];
bool valid()
{
    int N;
    cin >> N;

    string input;
    getline(cin, input);
    for (int i = 0; i < N; i++)
    {
        getline(cin, num[i]);
    }
    sort(num, num + N);
    
    set<string> st;
    st.insert(num[0]);
    for (int i = 1; i < N; i++)
    {
        string target = num[i];

        while (target.size() > 0)
        {
            if (st.count(target) == 1)
            {
                return false;
            }
            target.pop_back();
        }
        st.insert(num[i]);
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        cout << (valid() ? "YES" : "NO") << '\n';
    }

    return 0;
}