#include <iostream>
#include <vector>
using namespace std;
using lint = long long;

vector<lint> histogram;
lint search(int start, int end)
{
    if (start == end) return histogram[start];
    int mid = (start + end) / 2;
    lint result = max(search(start, mid), search(mid + 1, end));

    int left = mid, right = mid + 1;
    lint cur_width = right - left + 1;
    lint cur_height = min(histogram[left], histogram[right]);
    lint cur_area = cur_width * cur_height;
    result = max(result, cur_area);

    while (left > start || right < end)
    {
        if (right < end && (left == start || histogram[left - 1] < histogram[right + 1]))
        {
            cur_width++;
            cur_height = min(cur_height, histogram[++right]);
        }
        else
        {
            cur_width++;
            cur_height = min(cur_height, histogram[--left]);
        }

        result = max(result, cur_width * cur_height);
    }

    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    while (cin >> N)
    {
        if (N == 0) return 0;
        
        histogram.resize(N);

        for (int i = 0; i < N; i++)
        {
            cin >> histogram[i];
        }

        cout << search(0, N - 1) << '\n';
    }
}