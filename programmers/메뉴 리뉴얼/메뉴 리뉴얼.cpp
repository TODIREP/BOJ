#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int> mp;
string current, target;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

void make_comb(int X) {
    if (target.size() >= 2) {
        string item = target;
        sort(item.begin(), item.end());
        mp[item]++;
    }
    
    for (int index = X; index < current.size(); index++) {
        target.push_back(current[index]);
        make_comb(index + 1);
        target.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (auto order : orders) {
        current = order;
        target = "";
        make_comb(0);
    }
    vector<vector<pair<string, int> > > result(course.size());
    
    for (auto res : mp) {
        for (int index = 0; index < course.size(); index++) {
            if (course[index] != res.first.size()) continue;
            result[index].push_back(res);
        }
    }
    
    for (int index = 0; index < course.size(); index++) {
        if (result[index].size() < 1) continue;
        sort(result[index].begin(), result[index].end(), cmp);
        
        int count = result[index][0].second;
        if (count < 2) continue;
        
        for (auto res : result[index]) {
            if (res.second == count) {
                answer.push_back(res.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}