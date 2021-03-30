#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    
    int left = 0, right = people.size() - 1;
    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            right--;
        }
        answer++;
        left++;
    }
    return answer;
}