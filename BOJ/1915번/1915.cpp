#include <iostream>
using namespace std;

int arr[1002][1002];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    char input[1002];
    cin >> N >> M;

    for (int x = 1; x <= N; x++)
    {
        cin >> input;
        for (int y = 0; y < M; y++)
        {
            arr[x][y + 1] = (input[y] - '0');
        }
    }

    int answer = 0;
    for (int x = 1; x <= N; x++)
    {
        for (int y = 1; y <= M; y++)
        {
            if (arr[x][y] > 0)
            {
                arr[x][y] = min(arr[x - 1][y - 1], min(arr[x - 1][y], arr[x][y - 1])) + 1;
                answer = max(answer, arr[x][y]);
            }
        }
    }
    cout << answer * answer;
    return 0;
}