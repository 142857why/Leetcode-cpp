#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isMatch(char c1, char c2) {
    bool res = false;
    if (c1 == '(' && c2 == ')') res = true;
    if (c1 == '[' && c2 == ']') res = true;
    if (c1 == '{' && c2 == '}') res = true;
    return res;
}
bool isValid(string s) {
    stack<char> opt_stk;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            opt_stk.push(s[i]);
        } else {
            if (opt_stk.empty()) return false;
            if (isMatch(opt_stk.top(), s[i])) {
                opt_stk.pop();
            } else {
                return false;
            }
        }
    }
    return opt_stk.empty();
}

int main() {
    string s = "{[]}";
    if (isValid(s)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
