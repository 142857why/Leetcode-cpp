#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> removeInvalidParentheses(string s) {

}


int main() {
    string s = "(a)())()";
    vector<string> ans = removeInvalidParentheses(s);
    for (auto& s : ans) {
        cout << s << endl;
    }
    return 0;
}
