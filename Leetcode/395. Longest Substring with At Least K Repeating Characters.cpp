/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-02 19:03:02
 * @LastEditTime: 2021-03-02 20:30:47
 * @FilePath: \Leetcode\395.Longest Substring with At Least K Repeating Characters.cpp
 */
/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
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
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.3MB    BEAT:  81.96%    O(n) = 
LAST EDIT TIME: 2021年3月2日20:30:13
Description: 默写。依然。。难。
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k == 1) return s.length();
        if (s.length() < k) return 0;
        return longestSubStr(s, 0, s.length() - 1, k);
    }

    int longestSubStr(string& str, int start, int end, int k) {
        if (start >= end || end - start + 1 < k) return 0;

        vector<int> count(26, 0);

        for (int i = start; i <= end; i ++) {
            count[str[i] - 'a'] ++;
        }

        bool needSplit = false;
        for (int i = 0; i < 26; i ++) {
            if (count[i] > 0 && count[i] < k) {
                needSplit = true;
                break;
            }
        }

        if (!needSplit) return end - start + 1;

        int ans = 0;
        int left = start, right = start;

        while (right <= end) {
            while (left <= end) {
                if (count[str[left] - 'a'] >= k) break;
                left ++;
            }

            right = left + 1;

            while (right <= end) {
                if (count[str[right] - 'a'] > 0 && count[str[right] - 'a'] < k) break;
                right ++;
            }

            right --;
            if (right - left + 1 > ans) ans = max(ans, longestSubStr(str, left, right, k));

            left = right + 2;
        }

        return ans;
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.1MB    BEAT:  95.93%    O(n) = 
LAST EDIT TIME: 2021年3月2日19:40:54
Description: 分治 + 递归。
https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/solution/fen-zhi-jian-dan-jian-zhi-qing-song-100-ym8se/
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k == 1) return s.length();
        if (k > s.length()) return 0;
        return longestSubString(s, 0, s.length() - 1, k);
    }

    int longestSubString(string& str, int start, int end, int k) {
        if (start >= end || end - start + 1 < k) return 0; 

        vector<int> count(26, 0);

        for (int i = start; i <= end; i ++) {
            count[str[i] - 'a'] ++;
        }

        // 只分割一次。原本的想法是一次性把所有的全分割了。
        bool needSplit = false;
        for (int i = 0; i < 26; i ++) {
            if (count[i] > 0 && count[i] < k) {
                needSplit = true;
                break;
            }
        }

        if (!needSplit) return end - start + 1;

        int ret = 0;
        int left = start, right = start;
        while (right <= end) {
            while (left <= end) {
                if (count[str[left] - 'a'] >= k) break;
                left ++;
            }
            right = left + 1;

            while (right <= end) {
                if (count[str[right] - 'a'] > 0 && count[str[right] - 'a'] < k) break;
                right ++;
            }

            if (right - left > ret) ret = max(ret, longestSubString(str, left, right - 1, k));

            left = right + 1;
        }
        return ret;
    }
};

// @lc code=end

