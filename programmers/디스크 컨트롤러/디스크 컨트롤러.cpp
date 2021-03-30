#include <string>
#include <vector>
#include <queue>
using namespace std;

struct request {
    int start, end;
};

struct start_first {
    bool operator() (const request &a, const request &b) {
        if (a.start == b.start) {
            return a.end > b.end;
        }
        return a.start > b.start;
    }
};

struct end_first {
    bool operator() (const request &a, const request &b) {
        if (a.end == b.end) {
            return a.start > b.start;
        }
        return a.end > b.end;
    }
};

int solution(vector<vector<int>> jobs) {
    priority_queue<request, vector<request>, start_first> start_q;
    priority_queue<request, vector<request>, end_first> end_q;
    
    for (auto job : jobs) {
        start_q.push({job[0], job[1]});
    }
    
    int answer = 0, current = -1;
    while (!start_q.empty()) {
        current = start_q.top().start + start_q.top().end;
        answer += start_q.top().end;
        start_q.pop();
        
        while (!start_q.empty()) {
            if (start_q.top().start >= current) break;
            end_q.push(start_q.top());
            start_q.pop();
        }
        
        while (!end_q.empty()) {
            answer += (current - end_q.top().start + end_q.top().end);
            current += end_q.top().end;
            end_q.pop();
            
            while (!start_q.empty()) {
                if (start_q.top().start >= current) break;
                end_q.push(start_q.top());
                start_q.pop();
            }
        }
    }

    return answer / jobs.size();
}