#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int length = triangle.size();
    vector<vector<int>> res;
    res.resize(length);
    
    res[0].resize(1);
    res[0][0] = triangle[0][0];
    
    for (int index = 1; index < length; index++) {
        int len = triangle[index].size();
        res[index].resize(len);
        for (int next = 0; next < len; next++) {
            if (next == 0) res[index][next] = res[index - 1][next];
            else if (next == index) res[index][next] = res[index - 1][next - 1];
            else res[index][next] = max(res[index - 1][next - 1], res[index - 1][next]);
            res[index][next] += triangle[index][next];
        }
    }
    for (auto num : res[length - 1]) answer = max(answer, num);
    return answer;
}