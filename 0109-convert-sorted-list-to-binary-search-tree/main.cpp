#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createListNodeFromArray(const vector<int>& arr) {
    ListNode* tail = new ListNode(arr[0]);
    ListNode* head = tail;
    for (unsigned int i = 1; i < arr.size(); ++i) {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    while (head) {
        if (head->next) cout << head->val << "->"; else cout << head->val << endl;
        head = head->next;
    }
}

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
    int listLen(ListNode* head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }

    TreeNode* helper(ListNode* &node, int l, int r) {
        if (l > r) return nullptr;
        int m = l + (r - l) / 2;
        TreeNode* root = new TreeNode();
        root->left = helper(node, l, m - 1);
        root->val = node->val; node = node->next;
        root->right = helper(node, m + 1, r);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, 0, listLen(head) - 1);
    }
};

int main() {
    ListNode* head = createListNodeFromArray({-10, -3, 0, 5, 9});
    printLinkedList(head);
    Solution *obj = new Solution();
    BFS_print(obj->sortedListToBST(head));
    delete obj;
    return 0;
}
