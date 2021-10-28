#include <iostream>
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        for (auto c : s) {
            if (c == 'a' || c == 'b') {
                stk.push(c);
            } else if (c == 'c') {
                if (stk.size() < 2) {
                    return false;
                } else if (stk.top() != 'b') {
                    return false;
                } else {
                    stk.pop();
                    if (stk.top() != 'a') {
                        return false;
                    } else {
                        stk.pop();
                    }
                }
            } else {
                return false;
            }
        }
        return stk.empty();
    }
};

int main() {
    string s = "abcabcababcc";
    auto obj = std::unique_ptr<Solution>();
    bool f = obj->isValid(s);
    if (f) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
