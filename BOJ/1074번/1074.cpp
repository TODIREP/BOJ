#include <iostream>
using namespace std;

int N, R, C;
int search(int sx, int sy, int size, int start)
{
    if (size == 1) return start;

    int nxt_num = size * size / 4;
    int nxt_size = size / 2;

    int level = 0;
    for (int x = sx; x < sx + size; x += nxt_size)
    {
        for (int y = sy; y < sy + size; y += nxt_size)
        {
            if (R >= x && R < x + nxt_size && C >= y && C < y + nxt_size)
            {
                return search(x, y, nxt_size, start + nxt_num * level);
            }
            level++;
        }
    }
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> R >> C;
    cout << search(0, 0, (1 << N), 0);
    return 0;
}