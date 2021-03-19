#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K;
    cin >> K;

    set<int> st[9];
    int level = 1, nums = K;
    for (int index = 1; index <= 8; index++)
    {
        st[index].insert(nums);
        level *= 10;
        nums += level * K;
    }

    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i + j > 8) continue;

            for (auto A : st[i])
            {
                for (auto B : st[j])
                {
                    int nxt_num[5] = {A * B, A + B, A - B, A / B, B / A};

                    for (int dir = 0; dir < 5; dir++)
                    {
                        int nnum = abs(nxt_num[dir]);
                        if (nnum > 0)
                        {
                            st[i + j].insert(nnum);
                        }
                    }
                }
            }
        }
    }

    int N, number;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> number;
        bool valid = false;
        for (int index = 1; index <= 8; index++)
        {
            if (st[index].count(number) == 1)
            {
                cout << index << '\n';
                valid = true;
                break;
            }
        }
        if (valid) continue;
        cout << "NO\n";
    }

    return 0;
}