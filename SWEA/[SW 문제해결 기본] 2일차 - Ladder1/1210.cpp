#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	for(int test_case = 1; test_case <= 10; ++test_case)
	{
		int times;
        int map[101][101];
        int startX, startY;
        cin >> times;

        for (int x = 0; x < 100; x++) {
            for (int y = 0; y < 100; y++) {
                cin >> map[x][y];
                if (map[x][y] == 2) {
                    startX = x;
                    startY = y;
                }
            }
        }
        int dy[2] = {-1, 1};

        while (startX != 0) {
            map[startX][startY] = 0;
            bool turn = false;
            for (int dir = 0; dir < 2; dir++) {
                int ny = startY + dy[dir];
                if (ny < 0 || ny >= 100) continue;
                if (map[startX][ny] != 0) {
                    turn = true;
                    startY = ny;
                    break;
                }
            }
            if (!turn) {
                startX--;
            }
        }
        cout << "#" << times << " " << startY << "\n";
	}
	return 0;
}