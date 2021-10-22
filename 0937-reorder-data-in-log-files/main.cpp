#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {

    }
};
int main() {
    vector<string> logs{"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    vector<string> ans = (new Solution())->reorderLogFiles(logs);
    for (auto x : ans) {
        cout << x << endl;
    }
    return 0;
}
