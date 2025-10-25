#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

struct Cell {
    int r, c;
};

class Wave {
public:
    using Grid = std::vector<std::vector<char>>;

    static std::vector<std::vector<int>> computeDistances(const Grid& grid, Cell start) {
        int R = grid.size();
        int C = grid[0].size();
        std::vector<std::vector<int>> dist(R, std::vector<int>(C, -1));

        auto inside = [&](int r, int c) {
            return r >= 0 && r < R && c >= 0 && c < C;
            };

        std::queue<Cell> q;
        q.push(start);
        dist[start.r][start.c] = 0;

        const int dr[4] = { -1, 1, 0, 0 };
        const int dc[4] = { 0, 0, -1, 1 };

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (!inside(nr, nc)) continue;
                if (grid[nr][nc] == '#') continue;
                if (dist[nr][nc] != -1) continue;

                dist[nr][nc] = dist[r][c] + 1;
                q.push({ nr, nc });
            }
        }
        return dist;
    }

    static std::vector<Cell> reconstructPath(const std::vector<std::vector<int>>& dist, Cell start, Cell end) {
        std::vector<Cell> path;
        if (dist[end.r][end.c] == -1) return path;

        const int dr[4] = { -1, 1, 0, 0 };
        const int dc[4] = { 0, 0, -1, 1 };
        Cell cur = end;
        path.push_back(cur);

        while (!(cur.r == start.r && cur.c == start.c)) {
            int d = dist[cur.r][cur.c];
            bool found = false;
            for (int k = 0; k < 4; ++k) {
                int nr = cur.r + dr[k], nc = cur.c + dc[k];
                if (nr < 0 || nc < 0 || nr >= (int)dist.size() || nc >= (int)dist[0].size()) continue;
                if (dist[nr][nc] == d - 1) {
                    cur = { nr, nc };
                    path.push_back(cur);
                    found = true;
                    break;
                }
            }
            if (!found) return {};
        }
        std::reverse(path.begin(), path.end());
        return path;
    }
};
