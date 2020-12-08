#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    for (int test_case = 1; test_case <= 10; test_case++) {
        int map[9][9];
        char input[9];
        int length, count = 0, max;
        bool recursive;
        cin >> length;

        for (int x = 0; x < 8; x++) {
            cin >> input;
            for (int y = 0; y < 8; y++) {
                map[x][y] = input[y];
            }
        }

        max = length / 2;
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if (y + length - 1 < 8) {
                    recursive = true;
                    for (int index = 0; index < max; index++) {
                        if (map[x][index + y] != map[x][y + length - 1 - index]) {
                            recursive = false;
                            break;
                        }
                    }
                    if (recursive) count++;
                }
                if (x + length - 1 < 8) {
                    recursive = true;
                    for (int index = 0; index < max; index++) {
                        if (map[index + x][y] != map[x + length - 1 - index][y]) {
                            recursive = false;
                            break;
                        }
                    }
                    if (recursive) count++;
                }
            }
        }

        cout << "#" << test_case << " " << count << "\n";
    }
    return 0;
}