/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-20 14:20:59
 * @LastEditTime: 2020-12-20 20:12:30
 * @FilePath: \Leetcode\316.Remove Duplicate Letters.cpp
 */
/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> num(26);
        vector<bool> used(26);
        used.assign(26, false);
        
        string ans = "";
        
        for (char ch: s) {
            num[ch - 'a'] ++;
        }

        for (char ch: s) {
            
            num[ch - 'a'] -= 1;
            if (used[ch - 'a']) continue;

            while (ans.length() > 0 && ch < ans[ans.length() - 1] && num[ans[ans.length() - 1] - 'a'] > 0) {
                used[ans[ans.length() - 1] - 'a'] = false;
                ans.erase(ans.length() - 1);
            }

            used[ch - 'a'] = true;
            ans += ch;
        }
        return ans;
    }
};


int main() {
    Solution sol;
    // string ans = sol.removeDuplicateLetters("cbacdcbc");
    string ans = sol.removeDuplicateLetters("bcabc");
    cout << ans << endl;
    system("pause");
    return 0;
}
// @lc code=end

