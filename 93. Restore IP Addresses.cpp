/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-04 10:53:07
 * @LastEditTime: 2021-01-04 16:52:05
 * @FilePath: \Leetcode\93.Restore IP Addresses.cpp
 */
/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>
using namespace std;


/*
RESULT: Accept
TIME:   0ms    BEAT: 100.00%    O(n) = 
MEMORY: 7MB    BEAT:  41.31%    O(n) = 
Description: 递归 + 剪枝。
*/

class Solution {
public:

    vector<string> res;

    void dfs(string& s, int index, int num, string& per_str) {
        if (num == 4 || index == s.size()) {
            if (num == 4 && index == s.size())
                res.push_back(per_str.substr(0, per_str.size() - 1));
            return;
        }

        for (int i = 1; i <= 3; i ++) {
            if (index + i > s.size()) return;
            if (s[index] == '0' && i != 1) return;
            if (i == 3 && s.substr(index, i) > "255") return;

            per_str += s.substr(index, i);
            per_str.push_back('.');
            
            dfs(s, index + i, num + 1, per_str);
            per_str = per_str.substr(0, per_str.size() - i - 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        string per_str = "";
        dfs(s, 0, 0, per_str);
        return res;
    }
};


int main() {
    Solution sol;
    vector<string> ans = sol.restoreIpAddresses("25525511135");
    system("pause");
    return 0;
}

// @lc code=end

