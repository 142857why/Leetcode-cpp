#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string encode(string s) {
        int n = s.length();
        vector<vector<string>> dp(n, vector<string>(n, std::string()));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int endIndex = i + len - 1;
                string& ans = dp[i][endIndex];
                ans = s.substr(i, len);
                if (len >= 5) {
                    string temp = ans + ans;
                    int p = temp.find(ans, 1);
                    if (p < ans.length()) {
                        ans = to_string((ans.length() / p)) + "[" + dp[i][i+p-1] + "]";
                        continue;
                    }
                    for (int k = i; k < endIndex; ++k) {
                        if (dp[i][k].length() + dp[k+1][endIndex].length() < dp[i][endIndex].length()) {
                            //update dp[i - endIndex];
                            ans = dp[i][k] + dp[k+1][endIndex];
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};

int main() {
    std::shared_ptr<Solution> obj = std::make_unique<Solution>();
    string ans = obj->encode("abbbabbbcabbbabbbc");
    cout << ans << endl;
    return 0;
}
