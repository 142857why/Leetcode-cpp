#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool parseBoolExpr(string expression) {
        return false;
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
