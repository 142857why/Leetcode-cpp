#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trie {
public:
    Trie() {

    }

    void insert(string word) {

    }

    bool search(string word) {
        return false;
    }

    bool startWith(string prefix) {
        return false;
    }

};

int main() {
    auto* obj = new Trie();
    obj->insert("apple");
    obj->search("apple");
    obj->search("app");
    obj->startWith("app");
    obj->insert("app");
    obj->search("app");
    delete obj;
    return 0;
}
