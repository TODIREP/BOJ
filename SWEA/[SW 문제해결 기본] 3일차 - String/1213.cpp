#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case, T;
    char cmp_txt[11];
    char cmp_tar[1001];

	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int cmp_len = 0, index, count = 0;
        int cmp_pos[10] = { 0 };
        cin >> T >> cmp_txt >> cmp_tar;

        for (index = 0; cmp_txt[index] != '\0'; index++) {}
        cmp_len = index;

        for (index = cmp_len - 1; index >= 0; index--) {
            cmp_pos[index] = cmp_len - index - 1;
        }

        for (index = cmp_len - 1; cmp_tar[index] != '\0'; index++) {
            if (cmp_tar[index] == cmp_txt[cmp_len - 1]) {
                bool cmp_rst = true;
                for (int index2 = cmp_len - 1; index2 >= 0; index2--) {
                    if (cmp_tar[index - cmp_len + index2 + 1] != cmp_txt[index2]) {
                        cmp_rst = false;
                        break;
                    }
                }
                if (cmp_rst) count++;
                else index += cmp_len - 1;
            } else {
                int move = -1;
                for (int index2 = cmp_len - 1; index2 >= 0; index2--) {
                    if (cmp_txt[index2] == cmp_tar[index]) {
                        move = cmp_pos[index2];
                        break;
                    }
                }
                if (move != -1) {
                    index += move - 1;
                } else {
                    index += cmp_len - 1;
                }
            }
        }

        cout << "#" << T << " " << count << "\n";
	}
	return 0;
}