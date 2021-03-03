#include <string>
#include <vector>
using namespace std;

int LIMITS = 30000000;
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    vector<vector<int>> node(n + 1);
    for (int i = 1; i <= n; i++) {
        node[i].assign(n + 1, LIMITS);
    }
    
    for (auto fare : fares) {
        node[fare[0]][fare[1]] = fare[2];
        node[fare[1]][fare[0]] = fare[2];
    }
    
    for (int check = 1; check <= n; check++) {
        for (int x = 1; x <= n; x++) {
            if (x == check) continue;
            for (int y = 1; y <= n; y++) {
                if (y == check) continue;
                int distance = node[x][check] + node[check][y];
                if (distance < node[x][y]) {
                    node[x][y] = distance;
                }
            }
        }
    }
    
    answer = node[s][a] + node[s][b];
    for (int check = 1; check <= n; check++) {
        int course = node[s][check];
        if (a != check) course += node[check][a];
        if (b != check) course += node[check][b];
        answer = min(answer, course);
    }
    return answer;
}