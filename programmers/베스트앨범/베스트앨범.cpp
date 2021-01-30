#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct genre {
    int total;
    vector<pair<int, int> > play_list;
};

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, genre> m;
    map<int, vector<pair<int, int> >, greater<int> > res;
    
    int length = genres.size();
    for (int index = 0; index < length; index++) {
        m[genres[index]].total += plays[index];
        m[genres[index]].play_list.push_back({plays[index], index});
    }
    
    for (auto items : m) {
        sort(items.second.play_list.begin(), items.second.play_list.end(), cmp);
        res.insert({items.second.total, items.second.play_list});
    }
    
    for (auto result : res) {
        int count = 0;
        for (auto times : result.second) {
            if (count >= 2) break;
            answer.push_back(times.second);
            count++;
        }
    }
    return answer;
}