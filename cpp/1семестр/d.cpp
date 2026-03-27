#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

using namespace std;

int mazeSize = 15;
char** maze;

int playerX = 1;
int playerY = 1;

int exitX, exitY;

// Современная функция чтения символа
char getInput() {
#ifdef _WIN32
    return _getch(); // Современная версия для Windows
#else
    static struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    char ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
#endif
}

// Остальной код без изменений...
void createMazeArray() {
    maze = new char* [mazeSize];
    for (int i = 0; i < mazeSize; i++) {
        maze[i] = new char[mazeSize];
    }
}

void makeMaze() {
    for (int i = 0; i < mazeSize; i++) {
        for (int j = 0; j < mazeSize; j++) {
            maze[i][j] = '|';
        }
    }
    srand(time(0));

    exitX = mazeSize - 2;
    exitY = mazeSize - 2;

    vector<pair<int, int>> points;
    points.push_back(make_pair(1, 1));
    maze[1][1] = ' ';

    while (!points.empty()) {
        int randomIndex = rand() % points.size();
        int x = points[randomIndex].first;
        int y = points[randomIndex].second;

        points.erase(points.begin() + randomIndex);

        int directions[4][2] = { {0,2}, {2,0}, {0,-2}, {-2,0} };

        for (int i = 0; i < 4; i++) {
            int swapWith = rand() % 4;
            int tempX = directions[i][0];
            int tempY = directions[i][1];
            directions[i][0] = directions[swapWith][0];
            directions[i][1] = directions[swapWith][1];
            directions[swapWith][0] = tempX;
            directions[swapWith][1] = tempY;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            int wallX = x + directions[i][0] / 2;
            int wallY = y + directions[i][1] / 2;

            if (newX > 0 && newX < mazeSize - 1 && newY > 0 && newY < mazeSize - 1) {
                if (maze[newY][newX] == '|') {
                    maze[newY][newX] = ' ';
                    maze[wallY][wallX] = ' ';
                    points.push_back(make_pair(newX, newY));
                }
            }
        }
    }

    maze[exitY][exitX] = ' ';
    if (exitY - 1 >= 0 && maze[exitY - 1][exitX] == '|') maze[exitY - 1][exitX] = ' ';
    if (exitX - 1 >= 0 && maze[exitY][exitX - 1] == '|') maze[exitY][exitX - 1] = ' ';
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void drawMaze() {
    clearScreen();
    for (int i = 0; i < mazeSize; i++) {
        for (int j = 0; j < mazeSize; j++) {
            if (i == playerY && j == playerX) {
                cout << 'P';
            } else if (i == exitY && j == exitX) {
                cout << 'E';
            } else {
                cout << maze[i][j];
            }
        }
        cout << endl;
    }
    cout << "Управление: WASD для движения, Q для выхода" << endl;
}

int main() {
    createMazeArray();
    makeMaze();

    char input;
    bool gameRunning = true;

    while (gameRunning) {
        drawMaze();

        if (playerX == exitX && playerY == exitY) {
            cout << "Поздравляю! Вы нашли выход!" << endl;
            break;
        }

        input = getInput(); // Используем новую функцию

        int newX = playerX;
        int newY = playerY;

        switch (input) {
            case 'w': case 'W': newY--; break;
            case 's': case 'S': newY++; break;
            case 'a': case 'A': newX--; break;
            case 'd': case 'D': newX++; break;
            case 'q': case 'Q': gameRunning = false; break;
        }

        if (newX >= 0 && newX < mazeSize && newY >= 0 && newY < mazeSize &&
            maze[newY][newX] == ' ') {
            playerX = newX;
            playerY = newY;
        }
    }

    for (int i = 0; i < mazeSize; i++) {
        delete[] maze[i];
    }
    delete[] maze;

    return 0;
}