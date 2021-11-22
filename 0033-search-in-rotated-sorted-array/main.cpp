#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) return 01;
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            if (nums[0] <= nums[m]) {
                //the first half is still increasing ==> [l, m] increasing
                if (nums[0] <= target && target < nums[m]) {
                    // the target might fall into the increasing array [l, m]
                    r = m - 1;
                } else {
                    // the target might be somewhere else in the latter "rotated" array
                    l = m + 1;
                }
            } else {
                // we have already passed the "folding point";
                if (nums[m] < target && target <= nums[n-1]) {
                    // the target might fall into the latter increasing part, [l, r] is increasing!
                    l = m + 1;
                } else {
                    // the target might be somewhere else in the previous "rotated" array
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    auto* obj = new Solution();
    int index = obj->search(nums, target);
    cout << "index = " << index << endl;
    delete obj;
    return 0;
}
