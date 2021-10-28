#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
private:
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return ans;
        }
        helper("", n, n);
        return ans;
    }

    void helper(string s, int l, int r) {
        if (l == 0 && r == 0) {
            ans.emplace_back(s);
        }
        if (l == r) {
            helper(s + "(", l-1, r);
        } else if (l < r) {
            if (l > 0) {
                helper(s + "(", l-1, r);
            }
            helper(s+")", l, r-1);
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
