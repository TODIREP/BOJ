#include <iostream>
using namespace std;

int N, ans[10], oper[10][10];

bool check(int index)
{
    int sum = 0;
    for (int i = index; i >= 0; i--)
    {
        sum += ans[i];
        if (oper[i][index] > 0 && sum <= 0) return false;
        else if (oper[i][index] == 0 && sum != 0) return false;
        else if (oper[i][index] < 0 && sum >= 0) return false;
    }
    return true;
}

bool search(int index)
{
    if (index == N)
    {
        return true;
    }
    if (oper[index][index] == 0)
    {
        ans[index] = 0;
        return check(index) && search(index + 1);
    }
    for (int num = 1; num <= 10; num++)
    {
        ans[index] = num * oper[index][index];
        if (check(index) && search(index + 1)) return true;
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    char input[60];
    cin >> input;

    int index = 0;
    for (int x = 0; x < N; x++)
    {
        for (int y = x; y < N; y++)
        {
            if (input[index] == '0')
            {
                oper[x][y] = 0;
            }
            else if (input[index] == '+')
            {
                oper[x][y] = 1;
            }
            else
            {
                oper[x][y] = -1;
            }
            index++;
        }
    }
    search(0);
    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}