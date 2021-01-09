#include <iostream>

int main(void) {
    int N, input, arr[12];
    std::cin >> N;
    
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int index = 4; index < 11; index++) {
        arr[index] = arr[index - 1] + arr[index - 2] + arr[index - 3];
    }

    while (N--) {
        std::cin >> input;
        std::cout << arr[input] << "\n";
    }
    return 0;
}