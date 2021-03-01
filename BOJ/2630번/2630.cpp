#include <iostream>
using namespace std;

int paper[130][130], res[2];
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
        res[first] += 1;
        return;
    }

    int nxt_size = size / 2;

    for (int x = sx; x < sx + size; x += nxt_size)
    {
        for (int y = sy; y < sy + size; y += nxt_size)
        {
            search(x, y, nxt_size);
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

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            cin >> paper[x][y];
        }
    }

    search(0, 0, N);

    cout << res[0] << '\n' << res[1];
    return 0;
}