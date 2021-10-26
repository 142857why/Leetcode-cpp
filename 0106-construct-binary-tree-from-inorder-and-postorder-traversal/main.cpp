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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> hash;
        for (int i = 0; i < inorder.size(); ++i) {
            hash[inorder[i]] = i;
        }

        return helper(hash, postorder, 0, postorder.size() - 1, postorder.size() - 1);
    }

    TreeNode* helper(const unordered_map<int, int>& hash, const vector<int>& postorder, int s0, int e0, int s1) {
        if (s0 > e0) return nullptr;

        int mid = postorder[s1], index = hash.at(mid), rightLen = e0 - index + 1;
        TreeNode* node = new TreeNode(mid);
        node->left = helper(hash, postorder, s0, index - 1, s1 - rightLen);
        node->right = helper(hash, postorder, index + 1, e0, s1 - 1);
        return node;
    }
};

int main() {
    vector<int> inorder{9,3,15,20,7};
    vector<int> postorder{9,15,7,20,3};
    Solution* obj = new Solution();
    TreeNode* root = obj->buildTree(inorder, postorder);
    BFS_print(root);
    delete obj;
    return 0;
}
