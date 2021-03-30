#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int len = number.size(), current = 0;
    for (int index = 0; index < len - k; index++) {
        int choice = number[current] - '0';
        int ch_index = current;
        
        for (int target = current; target <= index + k; target++) {
            if (choice < (number[target] - '0')) {
                choice = number[target] - '0';
                ch_index = target;
            }
        }
        current = ch_index + 1;
        answer.push_back(choice + '0');
    }
    return answer;
}