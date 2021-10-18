#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include <cctype>

using namespace std;
class Solution {
private:
    unordered_map<char, int> priority {
            {'(', 0},
            {')', 0},
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2}
    };

    stack<char> opt_stk;
    stack<int> num_stk;

public:
    int calculate(string s) {
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i++;
                continue;
            } else if (isdigit(s[i])) {
                int num = s[i] - '0';
                while (i + 1 < n && isdigit(s[i+1])) {
                    num = num *  10 + (s[i+1] - '0');
                    i++;
                }
                num_stk.push(num);
            } else if (s[i] == '(') {
                opt_stk.push(s[i]);
            } else if (s[i] == ')') {
                while (!opt_stk.empty() && opt_stk.top() != '(') {
                    char opt = opt_stk.top(); opt_stk.pop();
                    int y = num_stk.top(); num_stk.pop();
                    int x = num_stk.top(); num_stk.pop();
                    int new_num = calcTwoNumbers(x, y, opt);
                    num_stk.push(new_num);
                }
                opt_stk.pop();
            } else {
                //it's operator +-*/
                while (!opt_stk.empty() && priority.at(opt_stk.top()) >= priority.at(s[i])) {
                    char opt = opt_stk.top(); opt_stk.pop();
                    int y = num_stk.top(); num_stk.pop();
                    int x = num_stk.top(); num_stk.pop();
                    int z = calcTwoNumbers(x, y, opt);
                    num_stk.push(z);
                }
                opt_stk.push(s[i]);
            }
            i++;
        }

        while (!opt_stk.empty()) {
            char opt = opt_stk.top(); opt_stk.pop();
            int y = num_stk.top(); num_stk.pop();
            int x = num_stk.top(); num_stk.pop();
            int z = calcTwoNumbers(x, y, opt);
            num_stk.push(z);
        }
        return num_stk.top();

    }

    int calcTwoNumbers(int x, int y, char opt) {
        int ans = 0;
        if (opt == '+') {
            ans = x + y;
        } else if (opt == '-') {
            ans = x - y;
        } else if (opt == '*') {
            ans = x * y;
        } else if (opt == '/') {
            ans = x / y;
        }
        return ans;
    }
};

int main() {
    string s;
    cin >> s;
    cout << (new Solution)->calculate(s) << endl;
}