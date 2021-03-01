#include <iostream>
using namespace std;

int paper[2200][2200], res[3];
void search(int sx, int sy, int size)
{
    bool same = true;

    int first = paper[sx][sy];

    for (int x = sx; x < sx + size; x++)
    {
        for (int y = sy; y < sy + size; y++)
        {
            if (paper[x][y] != first) same = false;
        }
    }

    if (same)
    {
        res[first + 1] += 1;
        return;
    }

    int nxt = size / 3;

    for (int x = sx; x < sx + size; x += nxt)
    {
        for (int y = sy; y < sy + size; y += nxt)
        {
            search(x, y, nxt);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int x = 1; x <= N; x++)
    {
        for (int y = 1; y <= N; y++)
        {
            cin >> paper[x][y];
        }
    }

    search(1, 1, N);
    
    cout << res[0] << '\n';
    cout << res[1] << '\n';
    cout << res[2] << '\n';
    return 0;
}