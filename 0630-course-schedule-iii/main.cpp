#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto& c1, const auto& c2) {
            return c1[1] < c2[1];
        });

        priority_queue<int> q;
        int total = 0;

        for (const auto& course : courses) {
            int ti = course[0], di = course[1];
            if (total + ti <= di) {
                total += ti;
                q.push(ti);
            } else if (!q.empty() && q.top() > ti) {
                total -= q.top() - ti;
                q.pop();
                q.push(ti);
            }
        }

        return q.size();
    }
};

int main() {
    vector<vector<int>> courses{{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};

    auto obj = new Solution();
    int ans = obj->scheduleCourse(courses);
    cout << ans << endl;
}