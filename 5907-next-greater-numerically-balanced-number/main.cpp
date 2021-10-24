#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
private:
//    vector<int> allBeautifulNumber{1, 22, 122, 212, 221, 333, 1333, 3133, 3313, 3331, 4444, 14444, 22333, 23233, 23323, 23332, 32233, 32323, 32332, 33223, 33232, 33322, 41444, 44144, 44414, 44441, 55555, 155555, 224444, 242444, 244244, 244424, 244442, 422444, 424244, 424424, 424442, 442244, 442424, 442442, 444224, 444242, 444422, 515555, 551555, 555155, 555515, 555551, 666666, 1666666}
    vector<int> allBeautifulNumber;
    void generateBeautifulNumber(string s) {
        do {
            allBeautifulNumber.push_back(stoi(s));
        } while (next_permutation(s.begin(), s.end()));
    }
    void initAllBeautifulNumber() {
        allBeautifulNumber.push_back(1);
        allBeautifulNumber.push_back(22);
        generateBeautifulNumber("122");
        allBeautifulNumber.push_back(333);
        generateBeautifulNumber("1333");
        allBeautifulNumber.push_back(4444);
        generateBeautifulNumber("14444");
        generateBeautifulNumber("22333");
        allBeautifulNumber.push_back(55555);
        generateBeautifulNumber("155555");
        generateBeautifulNumber("122333");
        generateBeautifulNumber("224444");
        allBeautifulNumber.push_back(666666);
        allBeautifulNumber.push_back(1224444);
        sort(allBeautifulNumber.begin(), allBeautifulNumber.end());
    };

    void printAllBeautifulNumbers() {
        for (auto x : allBeautifulNumber) {
            cout << x << ", ";
        }
        cout << endl;
    }
public:
    int nextBeautifulNumber(int n) {
        initAllBeautifulNumber();
        printAllBeautifulNumbers();
        auto it = lower_bound(allBeautifulNumber.begin(), allBeautifulNumber.end(), n);
        if (*it == n) {
            return *(++it);
        } else {
            return *it;
        }
    }
};
int main() {
    int n = 1;
    int ans = (new Solution())->nextBeautifulNumber(n);
    cout << ans << endl;
    return 0;
}
