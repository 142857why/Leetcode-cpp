#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        return 0;
    }
};

int main() {
    vector<vector<int>> courses{{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};

    auto obj = new Solution();
    int ans = obj->scheduleCourse(courses);
    cout << ans << endl;
}