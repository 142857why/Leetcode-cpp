#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {

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
