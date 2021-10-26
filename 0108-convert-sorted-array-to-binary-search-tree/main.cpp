#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* createTree(const vector<int>& arr) {
    deque<TreeNode*> pre;
    TreeNode* root = new TreeNode(arr[0]);
    pre.emplace_back(root);
    int index = 0;
    while (!pre.empty()) {
        deque<TreeNode*> cur;
        while (!pre.empty()) {
            TreeNode* node = pre.front(); pre.pop_front();
            TreeNode* left = nullptr;
            TreeNode* right = nullptr;
            if (++index < arr.size() && arr[index] != 0) {
                left = new TreeNode(arr[index]);
                cur.emplace_back(left);
            }
            if (++index < arr.size() && arr[index] != 0) {
                right = new TreeNode(arr[index]);
                cur.emplace_back(right);
            }
            node->left = left;
            node->right = right;
        }
        pre = cur;
    }
    return root;
}

void BFS_print(TreeNode *root ){
    cout << "[";
    std::queue<TreeNode *> Q;
    Q.push(root);
    while(!Q.empty()){
        TreeNode *node = Q.front();
        Q.pop();
        if (node) {
            cout << node->val << ", ";
        } else {
            cout << "null, ";
        }

        if(node && node->left){
            Q.push(node->left);
        } else if (node && node->right){
//            cout << "current node " << node->val << " has a empty child, push!\n";
            Q.push(nullptr);
        }
        if(node && node->right){
            Q.push(node->right);
        } else if (node && node->left){
            // cout << "current node " << node->val << " has a empty child, push!\n";
            Q.push(nullptr);
        }
    }
    cout << "\b\b]\n";
}

TreeNode* helper(const vector<int>&, int, int);

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
}

TreeNode* helper(const vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    int mid = left + (right - left) / 2;

    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);
    return root;
}

int main() {
    vector<int> nums{-10, -3, 1, 5, 9};
    TreeNode* root = createTree(nums);
//    TreeNode* root = sortedArrayToBST(nums);

    BFS_print(root);
//    printf("%d\n", root->left->left->left->val);

    return 0;
}
