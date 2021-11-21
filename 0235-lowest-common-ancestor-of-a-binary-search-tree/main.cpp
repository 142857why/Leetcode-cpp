#include "BinaryTree.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;
        while (true) {
            if (p->val < ans->val && q->val < ans->val) {
                ans = ans->left;
            } else if (p->val > ans->val && q->val > ans->val) {
                ans = ans->right;
            } else {
                break;
            }
        }
        return ans;
    }
};

int main() {
    auto* obj = new Solution();
    string line = "[6,2,8,0,4,7,9,null,null,3,5]";
    TreeNode* root = stringToTreeNode(line);
    TreeNode* ans = obj->lowestCommonAncestor(root, root->left->right, root->left->left);
    cout << ans->val << endl;
    delete obj;
    return 0;
}
