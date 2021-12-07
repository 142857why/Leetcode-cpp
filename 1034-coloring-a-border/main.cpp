#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        queue<vector<int>> q;
        q.push({row, col});
        while (!q.empty()) {
            vector<int> poll = q.front();
            q.pop();
            int x = poll[0], y = poll[1], cnt = 0;
            for (auto dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (grid[x][y] != grid[nx][ny])
                    continue;
                else
                    cnt++;
                if (ans[nx][ny] != 0) continue;
                q.push({nx, ny});
            }
            ans[x][y] = cnt == 4 ? grid[x][y] : color;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (ans[i][j] == 0) ans[i][j] = grid[i][j];
            }
        }
        return ans;
    }
};

void print2DVector(const vector<vector<int>>& v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            printf("%-12d", v[i][j]);
        }
        printf("\n");
    }
    printf("---------------------\n");
}

int main() {
    auto* obj = new Solution();
    vector<vector<int>> grid {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    print2DVector(grid);
    int row = 1, col = 1, color = 2;
    vector<vector<int>> ans = obj->colorBorder(grid, row, col, color);
    print2DVector(ans);
    delete obj;
}