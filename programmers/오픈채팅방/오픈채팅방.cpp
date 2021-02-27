#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<string> split(string target, char division) {
    vector<string> res;
    stringstream ss(target);
    string temp;
    
    while (getline(ss, temp, division)) res.push_back(temp);
    return res;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> res;
    vector<pair<string, string> > result;
    
    res["Enter"] = "님이 들어왔습니다.";
    res["Leave"] = "님이 나갔습니다.";
    
    for (auto cur : record) {
        auto item = split(cur, ' ');
        if (item[0].compare("Change") == 0 || item[0].compare("Enter") == 0) res[item[1]] = item[2];
        if (item[0].compare("Leave") == 0 || item[0].compare("Enter") == 0) result.push_back({item[1], item[0]});
    }
    for (auto r : result) answer.push_back(res[r.first] + res[r.second]);
    
    return answer;
}