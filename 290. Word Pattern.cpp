/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-16 14:23:43
 * @LastEditTime: 2020-12-16 15:02:59
 * @FilePath: \Leetcode\290.Word Pattern.cpp
 */
/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = m + n
MEMORY: 6.5MB    BEAT:  59.44%    O(n) = m + n
Description: 简单的【双射哈希表】思想。
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> str2ch;
        unordered_map<char, string> ch2str;
        
        int point = str.length();
        int i = 0;
        int j = i;
        for (auto ch: pattern) {
            if (i >= point) return false;
            j = i;
            while (j < point && str[j] != ' ') j ++;
            const string &tmp = str.substr(i, j - i);   // 引用传递，节省空间。

            if ((str2ch.count(tmp) && str2ch[tmp] != ch) || (ch2str.count(ch) && ch2str[ch] != tmp)) return false;
            
            str2ch[tmp] = ch;
            ch2str[ch] = tmp;

            i = j + 1;
        }

        return i >= point;
    }
};


int main() {
    Solution sol;
    bool ans = sol.wordPattern("abba", "dog cat cat fish");
    system("pause");
    return 0;
}
// @lc code=end

