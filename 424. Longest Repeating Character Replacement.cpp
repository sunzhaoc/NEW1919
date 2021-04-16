/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-02-02 22:33:21
 * @LastEditTime: 2021-02-02 23:29:51
 * @FilePath: \Leetcode\424.Longest Repeating Character Replacement.cpp
 */
/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
using namespace std;

/*
RESULT: Accept
TIME:     8ms    BEAT: 73.15%    O(n) = 
MEMORY: 6.9MB    BEAT: 91.04%    O(n) = 
LAST EDIT TIME: 2021年2月2日23:29:50
Description: 
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> num(26);
        int maxn = 0;
        int left = 0, right = 0;

        while (right < s.length()) {
            num[s[right] - 'A'] ++;
            maxn = max(maxn, num[s[right] - 'A']);
            if (right - left + 1 - maxn > k) {
                num[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};

// @lc code=end

