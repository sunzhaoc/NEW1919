/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-31 18:42:22
 * @LastEditTime: 2021-03-31 19:51:26
 * @FilePath: \Leetcode\744.Find Smallest Letter Greater Than Target.cpp
 */
/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
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
TIME:     8ms    BEAT: 81.72%    O(n) = 
MEMORY: 6.6MB    BEAT: 49.31%    O(n) = 
USED TIME: 忘记了。
LAST EDIT TIME: 2021年3月31日19:14:51
Description: 二刷。第一次python。二分。
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        target ++;
        int l = 0, r = letters.size();
        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (letters[mid] >= target) r = mid;
            else l = mid + 1;
        }
        target --;
        if (l >= letters.size() || (l == letters.size() - 1 && letters[l] == target)) return letters[0];
        if (letters[l] > target) return letters[l];
        return letters[l + 1];
    }
};

// @lc code=end

