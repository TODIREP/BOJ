#include <iostream>
#include <vector>
using namespace std;

int node[27][2];

void first(int cur)
{
    if (cur == -1) return;
    cout << (char) (cur + 'A');
    first(node[cur][0]);
    first(node[cur][1]);
}

void center(int cur)
{
    if (cur == -1) return;
    center(node[cur][0]);
    cout << (char) (cur + 'A');
    center(node[cur][1]);
}

void last(int cur)
{
    if (cur == -1) return;
    last(node[cur][0]);
    last(node[cur][1]);
    cout << (char) (cur + 'A');
}

int main(void)
{
    int N;
    char P[2], L[2], R[2];
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> P >> L >> R;
        if (L[0] != '.') node[P[0] - 'A'][0] = (L[0] - 'A');
        else node[P[0] - 'A'][0] = -1;
        if (R[0] != '.') node[P[0] - 'A'][1] = (R[0] - 'A');
        else node[P[0] - 'A'][1] = -1;
    }

    first(0);
    cout << '\n';
    center(0);
    cout << '\n';
    last(0);
    return 0;
}