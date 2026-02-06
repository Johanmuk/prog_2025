#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

/*
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
*/

struct Direction {
    int dx, dy;
};

const Direction dirs[8] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    { 0, -1},          { 0, 1},
    { 1, -1}, { 1, 0}, { 1, 1}
};

bool is_valid(int x, int y, int N, int M, const std::vector<std::string>& current_field) {
    return (x >= 0 && x < N) && (y >= 0 && y < M) && (current_field[x][y] != '#');
}

int Req(int x, int y, int endX, int endY, int N, int M, std::vector<std::vector<bool>> &visited, const std::vector<std::string>& current_field) {
    if (x == endX && y == endY) return 0;

    visited[x][y] = true;
    int min_dist = 1e9;

    for (int i = 0; i < 8; i++) {
        int nx = x + dirs[i].dx;
        int ny = y + dirs[i].dy;
        if (is_valid(nx, ny, N, M, current_field) && !visited[nx][ny]) {
            int d = Req(nx, ny, endX, endY, N, M, visited, current_field);
            if (d != -1) min_dist = std::min(min_dist, 1 + d);
        }
    }

    visited[x][y] = false;
    if (min_dist == 1e9) return -1;
    return min_dist;
}

int main() {
    int N, M;
    std::ifstream in("ex.txt");
    if (!in.is_open()) {
        std::cout << "File is not open" << std::endl;
        return -1;
    }
    
    in >> N >> M;
    std::vector<std::string> field;
    int startX = -1, startY = -1;
    int endX = -1, endY = -1;

    for (int i = 0; i < N; i++) {
        std::string tmp;
        in>>tmp;
        field.push_back(tmp);
        for (int j = 0; j < M; j++) {
            if (field[i][j] == 'S') {
                startX = i;
                startY = j;
            }
            if (field[i][j] == 'E') {
                endX = i;
                endY = j;
            }
        }
    }

    std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
    int result = Req(startX, startY, endX, endY, N, M, visited,field);
    std::cout << result << std::endl;
    std::cout << "Finished" << std::endl;

    return 0;
}