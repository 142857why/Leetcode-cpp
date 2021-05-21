#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
class Solution {

private:

    const string letterMap[10] = {
            " ",     //0
            "",      //1
            "abc",   //2
            "def",   //3
            "ghi",   //4
            "jkl",   //5
            "mno",   //6
            "pqrs",  //7
            "tuv",   //8
            "wxyz"  //9
    };

    vector<string> res;

    // s contains one current combination generating from digits[0..index-1]
    // use digits[index] to generate a new string (digits[0..index])
    void findCombinations(const string& digits, int index, const string& s) {
        // DEBUG BEGIN
        cout << index << " : " << s << endl;
        // DEBUG END

        if (index == digits.size() ) {
            //save s;
            res.push_back(s);
            cout <<  s << "被添加进最后的答案中" << std::endl;
            return;
        }
        char c = digits.at(index);
        assert(c >= '0' && c <= '9' && c!='1');
        string letters = letterMap[c - '0'];
        for (int i = 0; i < letters.size(); ++i) {
            //DEBUG BEGIN
            cout << "digits[" << index << "] = " << letterMap[c - '0'] << " , 准备使用 " << letters[i] << endl;
            //DEBUG END
            findCombinations(digits, index+1, s + letters[i]);
        }
        cout << "digits[" << index << "] = " << letterMap[c - '0'] << " 全部完成， return" << endl;
    }
public:
    vector<string> letterCombinations(string digits){
        res.clear();
        // border check
        if (digits.empty()) {
            return res;
        }
        findCombinations(digits, 0, "");
        return res;
    }
};
int main() {
    vector<string> ans = Solution().letterCombinations("234");
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans.at(i) << endl;
    }
    return 0;
}
