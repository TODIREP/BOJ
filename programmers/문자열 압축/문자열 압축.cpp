#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = s.size();
    
    for (int cut = 1; cut < s.size(); cut++) {
        vector<pair<string, int> > res;
        
        int current = 0;
        while (current < s.size()) {
            string word = s.substr(current, cut);
            
            if (res.size() == 0) {
                res.push_back({word, 1});
            } else {
                if (res.back().first.compare(word) == 0) {
                    res.back().second++;
                } else {
                    res.push_back({word, 1});
                }
            }
            current += cut;
        }
        
        int cnt = 0;
        for (auto r : res) {
            if (r.second > 1) {
                while (r.second > 0) {
                    cnt++;
                    r.second /= 10;
                }
            }
            cnt += r.first.size();
        }
        answer = min(answer, cnt);
    }
    return answer;
}