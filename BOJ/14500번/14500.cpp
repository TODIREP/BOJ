#include <iostream>
using namespace std;

pair<int, int> tetro[19][4] = {
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
    {{0, 1}, {1, 1}, {2, 0}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
    {{0, 1}, {1, 0}, {1, 1}, {2, 0}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 1}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}}
};

int world[501][501];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            cin >> world[x][y];
        }
    }

    int answer = 0;

    for (int choice = 0; choice < 19; choice++)
    {
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < M; y++)
            {
                int cur_sum = 0;
                bool valid = true;

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = x + tetro[choice][dir].first;
                    int ny = y + tetro[choice][dir].second;

                    if (nx >= N || ny >= M)
                    {
                        valid = false;
                        break;
                    }

                    cur_sum += world[nx][ny];
                }

                if (valid)
                {
                    answer = max(answer, cur_sum);
                }
            }
        }
    }

    cout << answer;
    return 0;
}