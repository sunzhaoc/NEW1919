/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-09 21:23:42
 * @LastEditTime: 2021-03-09 21:33:44
 * @FilePath: \Leetcode\14.Longest Common Prefix.cpp
 */
/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:      8ms    BEAT: 41.77%    O(n) = 
MEMORY: 15.2MB    BEAT:  5.01%    O(n) = 
USED TIME: 07:16
LAST EDIT TIME: 2021年3月9日21:31:52
Description: 
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int minLen = INT_MAX;
        for (string x: strs) {
            int y = x.length();
            minLen = min(minLen, y);
        }

        string res = "";        
        for (int i = 0; i < minLen; i ++) {
            char tmp = strs[0][i];
            for (string x: strs) {
                if (tmp != x[i]) return res;
            }
            res += tmp;
        }
        return res;
    }
};
// @lc code=end

