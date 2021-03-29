#include <vector>
#include <queue>
using namespace std;
using lint = long long;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<lint, vector<lint>, greater<lint>> pq(scoville.begin(), scoville.end());
    
    while (pq.size() >= 2 and pq.top() < K) {
        lint first = pq.top();pq.pop();
        lint second = pq.top();pq.pop();
        pq.push(first + second * 2);
        answer++;
    }
    
    return (pq.top() < K ? -1 : answer);
}