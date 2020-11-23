#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int length = prices.size();
    for (int x = 0; x < length; x++) {
        int counter = 0;
        for (int y = x + 1; y < length; y++) {
            counter++;
            if (prices[x] > prices[y]) break;
        }
        answer.push_back(counter);
    }
    return answer;
}