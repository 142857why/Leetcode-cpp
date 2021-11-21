#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Automaton {
    char state;
    unordered_map<char, vector<char>> table;
    int sign;
    long long ans;
    Automaton() : state('b'),
                  table({
                                                {'b', {'b', 's', 'n', 'e'}},
                                                {'s', {'e', 'e', 'n', 'e'}},
                                                {'n', {'e', 'e', 'n', 'e'}},
                                                {'e', {'e', 'e', 'e', 'e'}}
                  }),
                  sign(1),
                  ans(0) {

    }

    static int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' || c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == 'n') {
            ans = ans * 10  + (c - '0');
            if (sign == 1) {
                if (ans > (long long)INT_MAX) {
                    ans = INT_MAX;
                    state = 'e';
                }
            } else {
                if (ans > -(long long)INT_MIN) {
                    ans = INT_MIN;
                    state = 'e';
                }
            }
        } else if (state == 's') {
            sign = (c == '+') ? 1 : -1;
        }
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str) {
//            cout << "state = " << automaton.state << endl;
            automaton.get(c);
            if (automaton.state == 'e') break;
        }

        return automaton.sign * automaton.ans;
    }
};

int main() {
    auto* obj = new Solution();
    string s = "  -91283472332";
    int ans = obj->myAtoi(s);
    cout << ans << endl;
    delete obj;
    return 0;
}
