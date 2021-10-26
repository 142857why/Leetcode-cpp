#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class DFSSolution {
public:
    vector<string> removeInvalidParentheses(string s) {
        return vector<string>();
    }
};

class BFSSolution {
public:
    bool isValid(const string& st) {
        int count = 0;
        for (char c : st) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return (count == 0);
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> currSet;

        currSet.insert(s);
        while (true) {
            for (auto& str : currSet) {
                if (isValid(str)) {
                    ans.emplace_back(str);
                }
            }

            if (ans.size() > 0) return ans;

            unordered_set<string> nextSet;
            for (auto& str : currSet) {
                for (int i = 0; i < str.size(); ++i) {
                    if (i > 0 && str[i] == str[i-1]) continue;
                    if (str[i] == '(' || str[i] == ')') {
                        nextSet.insert(str.substr(0, i) + str.substr(i + 1));
                    }
                }
            }
            printCurrentSet(nextSet);
            currSet = nextSet;
        }
    }

    void printCurrentSet(const unordered_set<string> us) {
        cout << "----------------\n";
        for (auto it = us.begin(); it != us.end(); ++it) {
            cout << *it << endl;
        }
        cout << "-----------------\n";
    }
};


int main() {
    string s = "(a)())()";
    BFSSolution *obj = new BFSSolution();
    vector<string> ans = obj->removeInvalidParentheses(s);
    for (auto& s : ans) {
        cout << s << endl;
    }
    delete obj;
    return 0;
}
