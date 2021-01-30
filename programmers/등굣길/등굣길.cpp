#include <string>
#include <vector>
using namespace std;

long long area[102][102];
int solution(int m, int n, vector<vector<int>> puddles) {
    for (auto pos : puddles) {
        if (pos.size() == 0) continue;
        area[pos[1]][pos[0]] = -1;
    }
    
    area[1][1] = 1;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (area[x][y] == -1) continue;
            if (x + 1 <= n && area[x + 1][y] != -1) area[x + 1][y] = (area[x + 1][y] + area[x][y]) % 1000000007;
            if (y + 1 <= m && area[x][y + 1] != -1) area[x][y + 1] = (area[x][y + 1] + area[x][y]) % 1000000007;
        }
    }
    return area[n][m];
}