#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    for (int test_case = 1; test_case <= 10; test_case++) {
        int map[101][101];
        char input[101];
        int length, max = 0;
        bool recursive;
        cin >> length;

        for (int x = 0; x < 100; x++) {
            cin >> input;
            for (int y = 0; y < 100; y++) {
                map[x][y] = input[y];
            }
        }

        for (int x = 0; x < 100; x++) {
            for (int y = 0; y < 100; y++) {
                for (int len = max; len < 101; len++) {
                    length = len / 2;
                    if (y + len - 1 <= 100) {
                        recursive = true;
                        for (int index = 0; index < length; index++) {
                            if (map[x][y + index] != map[x][y + len - 1 - index]) {
                                recursive = false;
                                break;
                            }
                        }
                        if (recursive) {
                            max = len >= max ? len : max;
                        }
                    }
                    if (x + len - 1 <= 100) {
                        recursive = true;
                        for (int index = 0; index < length; index++) {
                            if (map[x + index][y] != map[x + len - 1 - index][y]) {
                                recursive = false;
                                break;
                            }
                        }
                        if (recursive) {
                            max = len >= max ? len : max;
                        }
                    }
                }
            }
        }

        cout << "#" << test_case << " " << max << "\n";
    }
    return 0;
}