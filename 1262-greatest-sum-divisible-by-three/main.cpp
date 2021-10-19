#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(), nums.end(), std::greater<int>());
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        //init dp table dp[pos][mod]
        dp[0][nums[0] % 3] = nums[0];
        for (int i = 1; i < n; ++i) {
            int tempModulo = nums[i] % 3;
            dp[i][tempModulo] = nums[i];
            switch (tempModulo) {
                case 0:
                    dp[i][0] = dp[i-1][0] + nums[i];
                    dp[i][1] = dp[i-1][1] != 0 ? dp[i-1][1] + nums[i] : 0;
                    dp[i][2] = dp[i-1][2] != 0 ? dp[i-1][2] + nums[i] : 0;
                    break;
                case 1:
                    dp[i][0] = std::max(dp[i-1][0], dp[i-1][2] != 0 ? dp[i-1][2] + nums[i] : 0);
                    dp[i][1] = std::max(dp[i-1][1], dp[i-1][0] != 0 ? dp[i-1][0] + nums[i] : 0);
                    dp[i][2] = std::max(dp[i-1][2], dp[i-1][1] != 0 ? dp[i-1][1] + nums[i] : 0);
                    break;
                case 2:
                    dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] != 0 ? dp[i-1][1] + nums[i] : 0);
                    dp[i][1] = std::max(dp[i-1][1], dp[i-1][2] != 0 ? dp[i-1][2] + nums[i] : 0);
                    dp[i][2] = std::max(dp[i-1][2], dp[i-1][0] != 0 ? dp[i-1][0] + nums[i] : 0);
                    break;
            }
        }
        printDpTable(dp);
        return dp[n-1][0];
    }

    void printDpTable(const vector<vector<int>>& v) {
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[0].size(); ++j) {
                cout << fixed << setw(4) << v[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-----DP Table Printing Finished-----\n";
    }

};


int main() {
    vector<int> v{2,19,6,16,5,10,7,4,11,6};
    cout << (new Solution)->maxSumDivThree(v) << endl;
    return 0;
}
