#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<string> split(string target, char delimiter) {
    vector<string> result;
    stringstream ss(target);
    string word;
    
    while (getline(ss, word, delimiter)) {
        result.push_back(word);
    }
    
    return result;
}

int data_score;
string anyone = "ALL";
unordered_map<string, vector<int>> info_list;
vector<string> data_list, temp_data;

void make_list(int start) {
    if (temp_data.size() > 0) {
        string cur = "";
        for (auto t : temp_data) {
            cur += t;
        }
        info_list[cur].push_back(data_score);
    }
    
    for (int index = start; index < data_list.size(); index++) {
        temp_data.push_back(data_list[index]);
        make_list(index + 1);
        temp_data.pop_back();
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for (auto i : info) {
        data_list = split(i, ' ');
        data_score = stoi(data_list.back());
        data_list.pop_back();
        make_list(0);
        info_list[anyone].push_back(data_score);
    }
    
    for (auto i : query) {
        data_list = split(i, ' ');
        data_score = stoi(data_list.back());
        data_list.pop_back();
        
        string query_data = "";
        for (auto r : data_list) {
            if (r.compare("and") == 0 || r.compare("-") == 0) continue;
            query_data += r;
        }
        if (query_data.size() == 0) query_data = anyone;
        
        int count = 0;
        auto check_score = info_list[query_data];
        
        for (auto scr : check_score) {
            if (scr >= data_score) count++;
        }
        answer.push_back(count);
    }
    return answer;
}