#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> target) {
    vector<int> answer;
    map<string, int> arr;
    
    int length = target.size();
    for (int index = 0; index < length; index++) {
        if (arr.find(target[index]) == arr.end()) {
           arr.insert({target[index], 0});
        }
    }
    
    int start = 0, end, total = arr.size(), cur_size = 0, cur_count = 0;
    int as, ae, a_size = 1000000;
    for (end = 0; end < total; end++) {
        auto cur_item = arr.find(target[end]);
        if (cur_item->second == 0) cur_size++;
        (cur_item->second)++;
        cur_count++;
    }
    end--;
    
    while (end < length) {
        if (cur_size == total) {
            if (cur_count < a_size && cur_size == total) {
                as = start;
                ae = end;
                a_size = cur_count;
            }
            auto target_item = arr.find(target[start]);
            target_item->second--;
            if (target_item->second == 0) cur_size--;
            cur_count--;
            start++;
            
        } else if (cur_size < total) {
            end++;
            if (end == length) break;
            auto target_item = arr.find(target[end]);
            cur_count++;
            target_item->second++;
            if (target_item->second == 1) cur_size++;
            
        } else {
            auto target_item = arr.find(target[start]);
            target_item->second--;
            if (target_item->second == 0) cur_size--;
            cur_count--;
            start++;
            
        }
        
        if (start > end) {
            end++;
            if (end == length) break;
            auto target_item = arr.find(target[end]);
            cur_count++;
            target_item->second++;
            if (target_item->second == 1) cur_size++;
            
        }
    }
    answer.push_back(as + 1);
    answer.push_back(ae + 1);
    return answer;
}