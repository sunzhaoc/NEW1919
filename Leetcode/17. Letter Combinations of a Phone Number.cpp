/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-04 14:02:52
 * @LastEditTime: 2021-01-06 13:34:02
 * @FilePath: \Leetcode\17.Letter Combinations of a Phone Number.cpp
 */
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-04 14:02:52
 * @LastEditTime: 2021-01-04 14:25:02
 * @FilePath: \Leetcode\17.Letter Combinations of a Phone Number.cpp
 */
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 39.47%    O(n) = 3^m * 4^n
MEMORY: 7.1MB    BEAT: 13.93%    O(n) = 3^m * 4^n
USED TIME: 18:57
Description: 递归。
*/

class Solution {
public:
    unordered_map<char, string> phoneMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> ans;

    void dfs(string& digits, int index, string& sub_str) {
        if (sub_str.length() == digits.length()) {
            ans.push_back(sub_str);
            return;
        }
        
        int num = phoneMap[digits[index]].length();
        for (int i = 0; i < num; i ++) {
            sub_str += phoneMap[digits[index]][i];
            dfs(digits, index + 1, sub_str);
            sub_str = sub_str.substr(0, sub_str.size() - 1);
        }
        
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        string sub_str = "";
        dfs(digits, 0, sub_str);
        return ans;
    }
};


int main() {
    Solution sol;
    vector<string> ans = sol.letterCombinations("");
    system("pause");
    return 0;
}

// @lc code=end

