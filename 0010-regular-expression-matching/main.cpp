#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        return false;
    }
};

int main() {
    auto* obj = new Solution();
    string s = "";
    string p = "";
    bool f = obj->isMatch(s, p);
    if (f) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    delete obj;
    return 0;
}
