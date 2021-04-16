/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-03 15:52:35
 * @LastEditTime: 2021-03-03 15:58:57
 * @FilePath: \Leetcode\242.Valid Anagram.cpp
 */
/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
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
TIME:    12ms    BEAT: 52.24%    O(n) = nlogn  排序的时间复杂度
MEMORY: 7.2MB    BEAT: 62.99%    O(n) = logn   排序的空间复杂度
LAST EDIT TIME: 2021年3月3日15:57:37
Description: 改进了一下。
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};


/*
RESULT: Accept
TIME:   20ms    BEAT: 34.37%    O(n) = nlogn
MEMORY:  7MB    BEAT: 96.11%    O(n) = logn
USED TIME: 02:11
LAST EDIT TIME: 2021年3月3日15:55:34
Description: 
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
// @lc code=end

