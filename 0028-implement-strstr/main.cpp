#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) { // 注意i从1开始
            while (j > 0 && s[i] != s[j]) { // 前后缀不相同了
                j = next[j - 1]; // 向前回退
            }
            if (s[i] == s[j]) { // 找到相同的前后缀
                j++;
            }
            next[i] = j; // 将j（前缀的长度）赋给next[i]
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0; // // 因为next数组里记录的起始位置为0
        for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
            while(j > 0 && haystack[i] != needle[j]) { // 不匹配
                j = next[j - 1]; // j 寻找之前匹配的位置
            }
            if (haystack[i] == needle[j]) { // 匹配，j和i同时向后移动
                j++; // i的增加在for循环里
            }
            if (j == (needle.size()) ) { // 文本串s里出现了模式串t
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

int main() {
    string s = "aabaaf";
    unsigned n = s.length();
    Solution* obj = new Solution();
    int next[n];
    obj->getNext(next, s);
    for (unsigned i = 0; i < n; ++i) {
        cout << next[i] << " ";
    }

    cout << endl;

    cout << obj->strStr("aabaabaafa", s);
    return 0;
}
