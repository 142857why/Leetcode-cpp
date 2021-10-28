#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n <= 0) {
            return ans;
        }
        helper("", n, n, ans);
        return ans;
    }

    void helper(string s, int l, int r, vector<string>& ans) {
//        cout << "l = " << l << ", r = " << r << endl;
        if (l == 0 && r == 0) {
//            cout << "s=" << s << endl;
            ans.push_back(s);
            return;
        }

        if (l == r) {
            helper(s + "(", l-1, r, ans);
        } else if (l < r) {
            if (l > 0) {
                helper(s + "(", l-1, r, ans);
            }
            helper(s + ")", l, r-1, ans);
        }
    }
};

int main() {
    auto it = std::unique_ptr<Solution>();
    cout << "[";
    int n = 3;
    vector<string> ret = it->generateParenthesis(n);
    for (const auto& s : ret) {
        cout << "\"" << s << "\"" << ",";
    }
    cout << "\b]\n";

    return 0;
}
