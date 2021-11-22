#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {

#define WALL (-1)
#define DOOR (0)
#define EMPTY_ROOM (2147483647)

private:
    // up, down, left, right
    int direction[4][2] = {
        {1, 0},
        {-1, 0},
        {0, -1},
        {0, 1},
    };
    queue<pair<int, int>> q;


public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if (!m) return;
        int n = rooms[0].size();
        if (!n) return;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == DOOR) q.emplace(make_pair(i, j));
            }
        }

        while (!q.empty()) {
            auto [row, col] = q.front(); q.pop();
            for (auto & dir : direction) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || rooms[newRow][newCol] != EMPTY_ROOM) continue;
                rooms[newRow][newCol] = rooms[row][col] + 1;
                q.emplace(make_pair(newRow, newCol));
            }
        }
    }
};

void print2DVector(const vector<vector<int>>& v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            printf("%-12d", v[i][j]);
        }
        printf("\n");
    }
}

int main() {
    vector<vector<int>> rooms {
            {INT_MAX, -1, 0, INT_MAX},
            {INT_MAX, INT_MAX, INT_MAX, -1},
            {INT_MAX, -1, INT_MAX, -1},
            {0, -1, INT_MAX, INT_MAX},
    };
//    print2DVector(rooms);
    auto* obj = new Solution();
    obj->wallsAndGates(rooms);
    print2DVector(rooms);
    delete obj;
    return 0;
}
