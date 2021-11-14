#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) { return encodedText;}
        int n = encodedText.size();
        if (n == 0) { return "";}
        int cols = n / rows;
        vector<vector<char>> arr(rows, vector<char>(cols, '\0'));
        for (int i = 0; i < n; ++i) {
            arr[i / cols][i % cols] = encodedText[i];
        }

//        printCharTable(arr);
        int i = 0, j = 0, j_start = 1;
        string ans = "";
        while (true) {
            ans += arr[i][j];
            if ((i == 0) && (j == cols-1)) break;
            if (i < rows - 1 && j < cols - 1) {
                i++;
                j++;
            } else {
                i = 0;
                j = j_start++;
//                cout << "j = " << j  << endl;
            }
        }
        ans.erase(ans.find_last_not_of(' ') + 1);
//        cout << ans.size() << endl;
        return ans;
    }

    void printCharTable(const vector<vector<char>>& v) {
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[0].size(); ++j) {
                cout << v[i][j];
            }
            cout << endl;
        }

    }
};
int main() {
//    string encoded = "iveo    eed   l te   olc";
    string encoded = "ch   ie   pr";
    int row = 3;
    auto* obj = new Solution();
    string ans = obj->decodeCiphertext(encoded, row);
    cout << ans << endl;
    delete obj;
    return 0;
}
