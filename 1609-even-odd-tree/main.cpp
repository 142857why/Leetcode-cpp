#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <sstream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

void BFS_print(TreeNode *root){
    if (!root) {
        cout << "[]" << endl;
        return;
    }
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root) que.push(root);
        int level = 0;
        while (!que.empty()) {
            int size = que.size();
            int prev = level % 2 == 0 ? INT_MIN : INT_MAX;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front(); que.pop();
                int value = node->val;
                if ((level & 1) == (value & 1)) return false;
                if (((level & 1) && (value >= prev)) || (!(level & 1) && (value <= prev))) return false;

                prev = value;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            level++;
        }
        return true;
    }
};


int main() {
    string treeString = "[5,9,1,3,5,7]";
    TreeNode* root = stringToTreeNode(treeString);
    auto* obj = new Solution();
    bool f = obj->isEvenOddTree(root);
    if (f) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    delete obj;
    return 0;
}
