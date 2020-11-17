#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<pair<int, int>> data;
    
    vector<vector<int>> visit;
    visit.resize(n);
    for (int index = 0; index < n; index++) {
        visit[index].assign(n, 0);
    }
    
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (computers[x][y] == 1 && visit[x][y] == 0) {
                answer++;
                data.push({x, y});
                
                while (!data.empty()) {
                    auto cur = data.front();
                    data.pop();
                    
                    for (int dir = 0; dir < n; dir++) {
                        if (computers[dir][cur.first] != 1) continue;
                        if (visit[dir][cur.first] == 1) continue;
                        
                        visit[dir][cur.first] = 1;
                        data.push({dir, cur.first});
                    }
                }
            }
        }
    }
    return answer;
}