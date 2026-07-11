#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        int fresh_oranges = 0;
        int time = 0;
        vector<vector<int>> visited(ROWS, vector<int>(COLS, 0));
        queue<pair<int,int>>q;
        for (int i = 0; i < ROWS; i++ ) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 1) {
                    fresh_oranges++;
                } else if (grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }

        int dir_x[4] = {0, 1, 0, -1};
        int dir_y[4] = {1, 0, -1, 0};
        while (fresh_oranges > 0 && !q.empty()) {
            int length = q.size();
            time++;
            for (int i = 0; i < length; i++) {
                auto [row, col] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int new_x = dir_x[k] + row;
                    int new_y = dir_y[k] + col;
                    if (new_x >= 0 && new_x < ROWS && new_y >= 0 && new_y < COLS &&  visited[new_x][new_y] == 0 && grid[new_x][new_y] == 1) {
                        fresh_oranges--;
                        q.push({new_x, new_y});
                        visited[new_x][new_y] = 1;
                    }
                }
            }
        }

        if (fresh_oranges == 0) return time;
        return -1;
        
    }
};