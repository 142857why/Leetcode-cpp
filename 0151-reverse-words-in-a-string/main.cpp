#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    void removeExtraSpaces(string& s) {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
        for (unsigned i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                s.erase(i, s.find_first_not_of(' ', i) - i - 1);
            }
        }
    }
public:
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s.begin(), s.end());
        unsigned int start = 0;
        for (unsigned i = 0; i < s.size() - 1; ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        reverse(s.begin() + start, s.end());
        return s;
    }
};

int main() {
    string s = "   the     sky is    blue   ";
    auto* obj = new Solution();
    string ans = obj->reverseWords(s);
    cout << "#" << ans << "#" << endl;
    delete obj;
    return 0;
}
