/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-27 20:43:44
 * @LastEditTime: 2021-04-27 20:45:36
 * @FilePath: \Leetcode\1392. Longest Happy Prefix.cpp
 */
/*
 * @lc app=leetcode.cn id=1392 lang=cpp
 *
 * [1392] 最长快乐前缀
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

/*
RESULT: Accept
TIME:     36ms    BEAT: 73.38%    O(n) = 
MEMORY: 18.6MB    BEAT: 60.46%    O(n) = 
USED TIME: 很快。
LAST EDIT TIME: 2021年4月27日20:44:23
Description: KMP
*/

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> ne(n);

        for (int i = 1, j = 0; i < n; i ++) {
            while (j && s[i] != s[j]) j = ne[j - 1];
            if (s[i] == s[j]) j ++;
            ne[i] = j;
        }

        return s.substr(0, ne.back());
    }
};
// @lc code=end

