#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        int n = gas.size(), i = 0;
        while (i < n) {
            int sumGas = 0, sumCost = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                sumCost += cost[j];
                sumGas += gas[i];
                if (sumCost > sumGas) {
                    break;
                }
                cnt++;
            }
            if (cnt == n) {
                return i;
            } else {
                i += (cnt + 1);
            }
        }
        return -1;
    }
};


int main() {
    auto obj = unique_ptr<Solution>();
    vector<int> gas{1, 2, 3, 4, 5}, cost{5, 4, 1, 2, 3};
    cout << obj->canCompleteCircuit(gas, cost) << endl;
    return 0;
}
