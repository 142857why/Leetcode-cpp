#include <iostream>
#include <string>

using namespace std;
class MapSum {
public:
    MapSum() {

    }

    void insert(string key, int val) {

    }

    int sum(string prefix) {

    }
};

int main() {
    auto* obj = new MapSum();
    obj->insert("apple", 3);
    obj->sum("ap");           // return 3 (apple = 3)
    obj->insert("app", 2);
    obj->sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
    delete obj;
    return 0;
}
