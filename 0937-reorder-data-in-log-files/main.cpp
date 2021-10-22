#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;
class Solution {
public:
    static bool cmp(const string& s1, const string s2) {
        int p1 = s1.find(' '), p2 = s2.find(' ');
        bool f1 = isalpha(s1[p1 + 1]), f2 = isalpha(s2[p2 + 1]);
        if(f1 && !f2) return true;
        if(f1 && f2){
            pair<string, string> pair1 = {s1.substr(p1), s1.substr(0, p1)};
            pair<string, string> pair2 = {s2.substr(p2), s2.substr(0, p2)};
            return pair1 < pair2;
        }
        return false;
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};

int main() {
    vector<string> logs{"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    vector<string> ans = (new Solution())->reorderLogFiles(logs);
    for (auto x : ans) {
        cout << x << endl;
    }
    return 0;
}
