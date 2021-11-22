#include <iostream>
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<char> opt_stk;
        stack<char> num_stk;
        for (int i = 0; i < expression.size(); ++i) {
            if (expression[i] == '.') continue;
            if (expression[i] == '|' || expression[i] == '&' || expression[i] == '!') {
                opt_stk.push(expression[i]);
            } else if (expression[i] == ')') {
                int t = 0;
                int f = 0;
                char c = num_stk.top();
                while (c != '(') {
                    if (c == 't') ++t;
                    if (c == 'f') ++f;
                    num_stk.pop();
                    c = num_stk.top();
                }
                num_stk.pop(); //pop (
                char op = opt_stk.top();
                opt_stk.pop();
                switch (op) {
                    case '!':
                        num_stk.push(t ? 'f' : 't');
                        break;
                    case '|':
                        num_stk.push(t ? 't' : 'f');
                        break;
                    case '&':
                        num_stk.push(f ? 'f' : 't');
                        break;
                }

            } else {
                num_stk.push(expression[i]);
            }

        }
        if (num_stk.top() == 't') return true; else return false;
    }
};

int main() {
    string s = "|(&(t,f,t),!(t))";
    auto* obj = new Solution();
    bool f = obj->parseBoolExpr(s);
    if (f) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    delete obj;
    return 0;
}
