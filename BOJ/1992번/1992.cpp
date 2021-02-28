#include <iostream>
using namespace std;

int N, paper[65][65];

void search(int sx, int sy, int N)
{
    bool same = true;
    int first = paper[sx][sy];
    for (int x = sx; x < sx + N; x++)
    {
        for (int y = sy; y < sy + N; y++)
        {
            if (paper[x][y] != first) 
            {
                same = false;
            }
        }
    }

    if (same)
    {
        cout << first;
        return;
    }
    cout << '(';
    int cut = N / 2;
    if (cut == 0)
    {
        for (int x = sx; x < sx + N; x++)
        {
            for (int y = sy; y < sy + N; y++)
            {
                cout << paper[x][y];
            }
        }
        return;
    }
    search(sx, sy, cut);
    search(sx, sy + cut, cut);
    search(sx + cut, sy, cut);
    search(sx + cut, sy + cut, cut);
    cout << ')';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char input[66];
    cin >> N;

    for (int x = 1; x <= N; x++)
    {
        cin >> input;
        for (int y = 1; y <= N; y++)
        {
            paper[x][y] = input[y - 1] - '0';
        }
    }
    search(1, 1, N);
    return 0;
}