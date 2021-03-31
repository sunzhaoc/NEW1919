/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-30 19:59:32
 * @LastEditTime: 2021-03-31 09:39:44
 * @FilePath: \Leetcode\278.First Bad Version.cpp
 */
/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 5.9MB    BEAT:  39.00%    O(n) = 
USED TIME: 02:45
LAST EDIT TIME: 2021年3月31日9:39:35
Description: 二分。
*/

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n;
        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (isBadVersion(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

// @lc code=end

