#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans(queries.size(), 0);
        int n = items.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (items[i][0] >= items[j][0]) {
                    items[i][1]  = std::max(items[i][1], items[j][1]);
                    std::swap(items[i][0], items[j][0]);
                }
            }
        }
        printVector(items);
        return ans;
    }
    void printVector(const vector<vector<int>>& v) {
        for (int i = 0; i < v.size(); ++i) {
            cout << "[" << v[i][0] << ", " << v[i][1] << "]  ";
        }
        cout << endl;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


/*
给你一个二维整数数组 items ，其中 items[i] = [price, beauty] 分别表示每一个物品的 价格 和 美丽值 。

同时给你一个下标从 0 开始的整数数组 queries 。对于每个查询 queries[j] ，你想求出价格小于等于 queries[j] 的物品中，最大的美丽值 是多少。
如果不存在符合条件的物品，那么查询的结果为 0 。

请你返回一个长度与 queries 相同的数组 answer，其中 answer[j]是第 j 个查询的答案。

 Example
 items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
 [2,4,5,5,6,6]

 */