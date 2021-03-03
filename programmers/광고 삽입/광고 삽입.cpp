#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using lint = long long;

lint tts(string target) {
    string hours = target.substr(0, 2);
    string minutes = target.substr(3, 2);
    string seconds = target.substr(6, 2);
    return stoi(hours) * 60 * 60 + stoi(minutes) * 60 + stoi(seconds);
}

string stt(lint target) {
    string seconds = to_string(target % 60);
    if (seconds.size() == 1) seconds = "0" + seconds;
    target /= 60;
    
    string minutes = to_string(target % 60);
    if (minutes.size() == 1) minutes = "0" + minutes;
    target /= 60;
    
    string hours = to_string(target);
    if (hours.size() == 1) hours = "0" + hours;
    return hours + ":" + minutes + ":" + seconds;
}

lint records[60 * 60 * 100 + 1], rec_sum[60 * 60 * 100 + 1];
string solution(string play_time, string adv_time, vector<string> logs) {
    map<lint, lint> mp;
    lint total_play = tts(play_time);
    lint ads_time = tts(adv_time);
    
    for (auto log : logs) {
        lint start_time = tts(log.substr(0, 8));
        lint end_time = tts(log.substr(9, 8));
        
        if (start_time > 0) mp[start_time] -= 1;
        mp[end_time] += 1;
    }
    
    vector<pair<lint, lint> > times;
    for (auto log : mp) times.push_back(log);
    sort(times.begin(), times.end(), greater<pair<lint, lint>>());
    
    lint sum = times[0].second;
    lint before = times[0].first;
    
    for (int i = 1; i < times.size(); i++) {
        for (int s = times[i].first + 1; s <= before; s++) records[s] += sum;
        sum += times[i].second;
        before = times[i].first;
    }
    
    rec_sum[0] = records[0];
    for (int i = 1; i <= total_play; i++) rec_sum[i] = rec_sum[i - 1] + records[i];
    
    lint ads_play = 0, start_time = 0;
    lint ads_start = 0, ads_end = ads_time;
    
    while (ads_end <= total_play) {
        lint ads_sum = rec_sum[ads_end];
        if (ads_start > 0) ads_sum -= rec_sum[ads_start];
        
        if (ads_sum > ads_play) {
            ads_play = ads_sum;
            start_time = ads_start;
        } else if (ads_sum == ads_play) {
            start_time = min(start_time, ads_start);
        }
        ads_start++;
        ads_end++;
    }
    
    return stt(start_time);
}