#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
private:
    unordered_map<string, bool> memo;

    bool dp(const string& s, int i, const string& p, int j) {
        if (j == p.size()) return (i == s.size());
        if (i == s.size()) {
            if ((p.size() - j) % 2) return false; // the remaining part of the pattern string must have even length
            while (j < p.size()) {
                if (p[j + 1] != '*') return false;
                j += 2;
            }
            return true;
        }

        string key = to_string(i) + ","  + to_string(j);
        if (memo.count(key)) return memo[key];

        bool res = false;
        if (s[i] == p[j] || p[j] == '.') {
            // match at the current position
            if (j < p.size() - 1 && p[j+1] == '*') {
                // now the next character is '*', we need to check whether it can match 0 or many times
                res = dp(s, i, p, j+2) || dp(s, i+1, p, j);
            } else {
                // single match, move both i and j
                res = dp(s, i+1, p, j+1);
            }
        } else {
            // doesn't match at the current position
            if (j < p.size() - 1 && p[j+1] == '*') {
                // now the next character is '*', this saves s[i] and p[j] temporarily, we need to skip the '*'
                res = dp(s, i, p, j + 2);
            } else {
                // no one can save the matching now
                res = false;
            }

        }
        return memo[key] = res;
    }
public:
    bool isMatch(string s, string p) {
        return dp(s, 0, p, 0);
    }
};

int main() {
    auto* obj = new Solution();
    string s = "aab";
    string p = "c*a*b";
    bool f = obj->isMatch(s, p);
    if (f) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    delete obj;
    return 0;
}
