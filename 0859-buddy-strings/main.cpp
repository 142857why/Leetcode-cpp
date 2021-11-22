#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        if (n != goal.length()) return false;
        int cnt[26]{0};
        bool hasDuplicateLetter = false;
        bool isSameString = true;
        int numOfDifference = 0;
        char c1 = 0, c2 = 0;
        for (int i = 0; i < n; ++i) {
            if (++cnt[s[i] - 'a'] == 2) {
                hasDuplicateLetter = true;
            }
            if (s[i] != goal[i]) {
                isSameString = false;
                if (numOfDifference == 2) {
                    return false;
                } else if (numOfDifference == 1) {
                    if ((c1 != goal[i]) || (c2 != s[i])) {
                        return false;
                    } else {
                        numOfDifference++;
                    }
                } else {
                    c1 = s[i];
                    c2 = goal[i];
                    numOfDifference++;
                }
            }
        }

        if ((numOfDifference == 2) || (isSameString && hasDuplicateLetter)) return true; else return false;
    }
};

int main() {
    string s = "ab";
    string goal = "ba";
    auto* obj = new Solution();
    if (obj->buddyStrings(s, goal)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
