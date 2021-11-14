#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    const vector<string> singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const vector<string> thousands = {"", "Thousand", "Million", "Billion"};
public:

    string toEnglish(int num) {
        string ret;
        int hundred = num / 100;
        num %= 100;
        if (hundred != 0) {
            ret += singles[hundred] + " Hundred ";
        }
        int ten = num / 10;
        if (ten >= 2) {
            ret += tens[ten] + " ";
            num %= 10;
        }
        if (num > 0 && num < 10) {
            ret += singles[num] + " ";
        } else if (num >= 10) {
            ret += teens[num-10] + " ";
        }
        return ret;
    }

    string numberToWords(int num) {
        if (num == 0) {return "Zero";}

        string ans;
        for (int i = 3, unit = 1000000000; i >= 0; i--, unit /= 1000) {
            int curr = num / unit;
            if (curr != 0) {
                num -= curr * unit;
                ans += toEnglish(curr) + thousands[i] + " ";
            }
        }
        while (ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};
int main() {
    auto* obj = new Solution();
    string ans = obj->numberToWords(1234567891);
    cout << ans << endl;
    delete obj;
    return 0;
}
