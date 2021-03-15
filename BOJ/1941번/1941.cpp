#include <iostream>
#include <queue>
using namespace std;

bool check[5][5], val[5][5];
pair<int, int> school[26], student[7];
int answer = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void search(int count, int start, int som)
{
    if (count == 7)
    {
        queue<pair<int, int>> q, repair;
        q.push({student[0]});
        repair.push({student[0]});
        val[student[0].first][student[0].second] = false;
        
        int counter = 1;
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                
                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if (!val[nx][ny]) continue;

                val[nx][ny] = false;
                counter++;
                q.push({nx, ny});
                repair.push({nx, ny});
            }
        }

        while (!repair.empty())
        {
            auto cur = repair.front();
            repair.pop();
            val[cur.first][cur.second] = true;
        }

        if (counter < 7) return;
        answer += (som >= 4);
        return;
    }

    for (int index = start; index < 25; index++)
    {
        student[count] = school[index];
        int nsom = som + check[student[count].first][student[count].second];
        val[student[count].first][student[count].second] = true;
        search(count + 1, index + 1, nsom);
        val[student[count].first][student[count].second] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char input[8];
    for (int x = 0; x < 5; x++)
    {
        cin >> input;
        for (int y = 0; y < 5; y++)
        {
            check[x][y] = (input[y] == 'S');
            school[x * 5 + y] = {x, y};
        }
    }
    search(0, 0, 0);
    cout << answer;
    return 0;
}