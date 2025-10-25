#include <iostream>
#include "waveAlg.h"

int main() {
    int R, C;
    std::cout << "Enter grid size (rows cols): ";
    std::cin >> R >> C;
    std::cin.ignore();

    Wave::Grid grid(R, std::vector<char>(C));
    Cell start{ -1, -1 }, end{ -1, -1 };

    std::cout << "Enter grid (" << R << " lines, using S = start, D = dest, # = wall, . = free)" <<std::endl;
    for (int i = 0; i < R; ++i) {
        std::string line;
        std::getline(std::cin, line);
        for (int j = 0; j < C; ++j) {
            grid[i][j] = line[j];
            if (grid[i][j] == 'S') start = { i, j };
            else if (grid[i][j] == 'D') end = { i, j };
        }
    }

    if (start.r == -1 || end.r == -1) {
        std::cout << "Error: Missing S or D in grid. " << std::endl;
        return 1;
    }

    auto dist = Wave::computeDistances(grid, start);
    auto path = Wave::reconstructPath(dist, start, end);

    if (path.empty()) {
        std::cout << "No path found." << std::endl;
    }
    else {
        for (auto& p : path) {
            if (grid[p.r][p.c] == '.' || grid[p.r][p.c] == 'S' || grid[p.r][p.c] == 'D')
                if (grid[p.r][p.c] != 'S' && grid[p.r][p.c] != 'D')
                    grid[p.r][p.c] = '*';
        }

        std::cout << "\nShortest path length: " << dist[end.r][end.c] << std::endl;
        std::cout << "Grid with path: " <<std::endl;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j)
                std::cout << grid[i][j];
            std::cout << std::endl;
        }
    }

    return 0;
}
