#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> cur2parent;
        int n = regions.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < regions[i].size(); ++j) {
//                cout << regions[i][j] << " -- ";
                cur2parent[regions[i][j]] = regions[i][0];
            }
        }

        unordered_set<string> r1_ancestor;
        string r1 = region1;
        while (!r1.empty()) {
            r1_ancestor.insert(r1);
            r1 = cur2parent[r1];
        }
        string r2 = region2;
        while (!r2.empty()) {
            if (r1_ancestor.count(r2)) {
                return r2;
            }
            r2 = cur2parent[r2];
        }
        return "";
    }
};

int main() {
    vector<vector<string>> regions = {
            {"Earth","North America","South America"},
            {"North America","United States","Canada"},
            {"United States","New York","Boston"},
            {"Canada","Ontario","Quebec"},
            {"South America","Brazil"},
    };
    string region1 = "Quebec";
    string region2 = "New York";
    auto* obj = new Solution();
    string ans = obj->findSmallestRegion(regions, region1, region2);
    cout << ans << endl;
    delete obj;
    return 0;
}
