#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> res;
    for (auto cloth: clothes) res[cloth[1]]++;
    for (auto result: res) answer *= (result.second + 1);
    return answer - 1;
}