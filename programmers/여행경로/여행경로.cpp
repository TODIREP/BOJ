#include <string>
#include <vector>
using namespace std;

vector<bool> used;
vector<string> temp, answer;
int ticket_len;
void search(vector<vector<string>> &ticket, string cur, int cnt) {
    if (cnt == ticket_len) {
        if (answer.size() == 0) answer = temp;
        else {
            int index = 0;
            while (answer[index] == temp[index]) index++;
            if (index <= cnt and answer[index].compare(temp[index]) > 0) {
                answer = temp;
            }
        }
        return;
    }
    for (int index = 0; index < ticket_len; index++) {
        if (ticket[index][0].compare(cur) != 0 or used[index]) continue;
        temp.push_back(ticket[index][1]);
        used[index] = true;
        search(ticket, ticket[index][1], cnt + 1);
        temp.pop_back();
        used[index] = false;
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    ticket_len = tickets.size();
    used.assign(ticket_len, false);
    temp.push_back("ICN");
    search(tickets, "ICN", 0);
    return answer;
}