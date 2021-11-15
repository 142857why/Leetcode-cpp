#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        unsigned int q_size = queries.size();
        vector<int> ans(q_size, 0);
        unsigned int n = items.size();
        sort(items.begin(), items.end(), [&](auto& a, auto& b)->bool {
           if (a[0] == b[0]) {
               return a[1] > b[1];
           }
            return a[0] < b[0];
        });
//        print2DVector(items);
        vector<int> f(n, 0);
        f[0] = items[0][1];
        for (unsigned i = 1; i < n; ++i) {
            f[i] = std::max(f[i-1], items[i][1]);
        }
//        print1DVector(f);
        for (unsigned int i = 0; i < q_size; ++i) {
            int l = 0, r = n, p = queries[i];
            while (l < r) {
                unsigned m = l + (r - l) / 2;
                if (items[m][0] < p) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            if (l == n || items[l][0] > p) {
                --l;
            }
            ans[i] = l >= 0 ? f[l] : 0;
        }

        return ans;
    }

    static void print2DVector(const vector<vector<int>>& v) {
        for (int i = 0; i < v.size(); ++i) {
            cout << "[" << v[i][0] << ", " << v[i][1] << "]  ";
        }
        cout << endl;
    }

    static void print1DVector(const vector<int>& v) {
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

void printAns(const vector<int>& v) {
    cout << "[";
    for (auto x : v) {
        cout << x << ", ";
    }
    cout << "\b\b]\n";
}

int main() {
    vector<vector<int>> items{{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
    vector<int> queries{1, 2, 3, 4, 5, 6};

    auto* obj = new Solution();
    vector<int> ans = obj->maximumBeauty(items, queries);
    printAns(ans);
    delete obj;
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