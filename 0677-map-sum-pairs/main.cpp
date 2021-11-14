#include <iostream>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    int val;
    TrieNode() : val(0) {
        for (unsigned int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class MapSum {
private:
    TrieNode* root;

public:
    MapSum() : root(new TrieNode()) {

    }

    void insert(string key, int val) {
        TrieNode* temp = root;
        for (unsigned i = 0; i < key.size(); ++i) {
            unsigned index = key[i] - 'a';
            if (!temp->children[index]) {
                temp->children[index] = new TrieNode();
            }
            temp = temp->children[index];
        }
        temp->val = val;
    }

    int sum(string prefix) {
        TrieNode* temp = root;
        for (unsigned i = 0; i < prefix.size(); ++i) {
            if (!temp) {
                return 0;
            }
            temp = temp->children[prefix[i] - 'a'];
        }
        return dfs(temp);
    }

private:
    int dfs(TrieNode* node) {
        if (!node) {
            return 0;
        }
        int ans = node->val > 0 ? node->val : 0;
        for (auto child : node->children) {
            ans += dfs(child);
        }
        return ans;
    }

};

int main() {
    auto* obj = new MapSum();
    obj->insert("apple", 3);
    cout << obj->sum("ap") << endl;           // return 3 (apple = 3)
    obj->insert("app", 2);
    cout << obj->sum("ap") << endl;           // return 5 (apple + app = 3 + 2 = 5)
    delete obj;
    return 0;
}
