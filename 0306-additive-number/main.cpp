#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool isAdditiveNumber(string num) {
        return false;
    }
};

int main() {
    auto* obj = new Solution();
    string num = "1123581321";
    bool res = obj->isAdditiveNumber(num);
    if (res) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    delete obj;
    return 0;
}
