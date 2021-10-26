#include <iostream>

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_map>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void BFS_print(TreeNode *root ){
    string res = "[";
    std::queue<TreeNode *> Q;
    Q.push(root);
    while(!Q.empty()){
        TreeNode *node = Q.front();
        Q.pop();
        if (node) {
            res += to_string((node->val));
            res += ", ";
        } else {
            res += "#";
        }

        if(node && node->left){
            Q.push(node->left);
        } else if (node){
//            cout << "current node " << node->val << " has a empty child, push!\n";
            Q.push(nullptr);
        }
        if(node && node->right){
            Q.push(node->right);
        } else if (node){
            // cout << "current node " << node->val << " has a empty child, push!\n";
            Q.push(nullptr);
        }
    }
    for (unsigned i = res.length() - 1; i >= 0; i--) {
        if (res[i] != '#') {
            res = res.substr(0, i);
            break;
        }
    }
    for (auto x : res) {
        if (x == '#') {
            cout << "null, ";
        } else {
            cout << x;
        }
    }
    cout << "\b]\n";
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        unordered_map<int, int> hash;
        for (int i = 0; i < inorder.size(); ++i) {
            hash[inorder[i]] = i; // since there is no duplicate element

        }
        return builder(hash, preorder, 0, preorder.size() - 1, 0);
    }

    TreeNode* builder(unordered_map<int, int>& hash, vector<int>& preorder, int s0, int e0, int s1) {
        if (s0 > e0) return nullptr;
        int mid = preorder[s1], index = hash[mid], leftLen = index - s0;
        TreeNode* node = new TreeNode(mid);
        node->left = builder(hash, preorder, s0, index - 1, s1 + 1);
        node->right = builder(hash, preorder, index + 1, e0, s1 + leftLen + 1);
        return node;
    }
};

int main() {
    Solution* obj = new Solution();
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    TreeNode* root = obj->buildTree(preorder, inorder);
    BFS_print(root);
    delete obj;
    return 0;
}
