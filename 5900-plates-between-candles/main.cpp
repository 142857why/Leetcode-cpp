#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    void init(const string& s, vector<int>& startTable, vector<int>& endTable, vector<int>& valueSumTable) {
        int i_first = s.find_first_of("|");
        int i_last = s.find_last_of("|");
        if (i_first == i_last) {
            return;
        }
//        cout << "first_position = " << i_first << endl;
//        cout << "last_position = " << i_last << endl;
        int last_start = i_first, tempSum = 0;
        for (int i = i_first + 1; i <= i_last; ++i) {
            if (s[i] == '*') {
                tempSum++;
            } else if (s[i] == '|') {
                startTable.emplace_back(last_start);
                endTable.emplace_back(i);
                valueSumTable.emplace_back(tempSum);


                while (i < i_last && s[i + 1] == '|') {
                    ++i;
                }
                last_start = i;
            }
        }
//        printVector(startTable);
//        printVector(endTable);
//        printVector(valueSumTable);
    }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> startTable;
        vector<int> endTable;
        vector<int> valueSumTable;
        init(s, startTable, endTable, valueSumTable);
        vector<int> ans(queries.size(), 0);
        if (startTable.empty()) {
            return ans;
        }
        for (int i = 0; i < queries.size(); ++i) {
            auto it_start = lower_bound(startTable.begin(), startTable.end(), queries[i][0]);

            auto it_end = upper_bound(endTable.begin(), endTable.end(), queries[i][1]) - 1;

            int start_index = it_start - startTable.begin();
            int end_index = it_end - endTable.begin();

            if (it_start == startTable.end() || it_end == startTable.end()) {
                continue;
            }

            if (start_index > end_index) continue;
            ans[i] = (start_index == 0) ? valueSumTable[end_index] : valueSumTable[end_index] - valueSumTable[start_index - 1];
        }
        return ans;
    }

    void printVector(const vector<int>& v) {
        cout << "[";
        for (auto x : v) {
            cout << x << ",";
        }
        cout << "\b]\n";
    }
};


int main() {
    string s = "***|**|*****|**||**|*";
    vector<vector<int>> queries {{1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}};
    Solution* obj = new Solution();
    vector<int> ans = obj->platesBetweenCandles(s, queries);
    obj->printVector(ans);
    return 0;
}
