#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

const int WIDTH = 21;
const int HEIGHT = 21;

enum Cell {
    WALL,
    PATH
};

void dfs(int x, int y, std::vector<std::vector<Cell>>& maze) {
    static const int dx[] = { 0, 1, 0, -1 };
    static const int dy[] = { -1, 0, 1, 0 };

    int dirList[] = { 0, 1, 2, 3 };
    for (int i = 0; i < 4; ++i) {
        int r = rand() % 4;
        std::swap(dirList[i], dirList[r]);
    }

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[dirList[i]] * 2;
        int ny = y + dy[dirList[i]] * 2;
        if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && maze[ny][nx] == WALL) {
            maze[y + dy[dirList[i]]][x + dx[dirList[i]]] = PATH;
            maze[ny][nx] = PATH;
            dfs(nx, ny, maze);
        }
    }
}

std::vector<std::vector<Cell>> generateMaze(int width, int height) {
    std::vector<std::vector<Cell>> maze(height, std::vector<Cell>(width, WALL));

    maze[0][1] = PATH;
    maze[height - 1][width - 2] = PATH;

    srand(time(NULL));
    dfs(1, 1, maze);

    return maze;
}

void printMaze(const std::vector<std::vector<Cell>>& maze) {
    for (const auto& row : maze) {
        for (const auto& cell : row) {
            std::cout << (cell == WALL ? '#' : ' ');
        }
        std::cout << '\n';
    }
}

int main() {
    std::vector<std::vector<Cell>> maze = generateMaze(WIDTH, HEIGHT);
    printMaze(maze);

    system("pause");
    return 0;
}