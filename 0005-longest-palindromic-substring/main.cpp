#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        int start = 0, end = 0, maxLength = 1;
        for (int i = 0; i < s.length(); ++i) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            int len = std::max(len1, len2);
            if (len > (end - start)) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
                maxLength = len ;
            }
        }
//        cout << "max length = " << maxLength << endl;
        return s.substr(start, maxLength);
    }

    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }

};
int main() {
    string s;
    getline(cin, s);
    string ans = ((new Solution())->longestPalindrome(s));
    cout << ans << endl;
    return 0;
}
