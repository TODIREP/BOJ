#include <iostream>
using namespace std;

int num[2001];
bool palin[2001][2001];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        palin[i][i] = true;

        for (int k = i - 1; k >= 0; k--)
        {
            int pl = k + 1, pr = i - 1;
            if (num[k] == num[i])
            {
                if (pl > pr)
                {
                    palin[i][k] = true;
                }
                else
                {
                    palin[i][k] = palin[pr][pl];
                }
            }
            else
            {
                palin[i][k] = false;
            }
        }
    }
    
    int M, S, E;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> S >> E;
        cout << palin[E - 1][S - 1] << '\n';
    }

    return 0;
}