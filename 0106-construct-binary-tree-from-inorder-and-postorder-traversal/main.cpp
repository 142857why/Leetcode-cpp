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
        return nullptr;
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
