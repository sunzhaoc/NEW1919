/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-27 16:06:52
 * @LastEditTime: 2020-12-27 16:15:41
 * @FilePath: \Leetcode\205.同构字符串.cpp
 */
/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
#include<unordered_map>
using namespace std;

/*
RESULT: Accept
TIME:    36ms    BEAT: 13.81%    O(n) = 
MEMORY: 7.4MB    BEAT: 19.28%    O(n) = 
Description: 双射哈希表。
*/ 

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t, t2s;
        int len = s.size();
        for (int i = 0; i < len; i ++) {
            char x = s[i], y = t[i];
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }   
        return true;     
    }
};
// @lc code=end

