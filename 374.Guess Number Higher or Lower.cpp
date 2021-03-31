/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-31 10:02:35
 * @LastEditTime: 2021-03-31 10:06:05
 * @FilePath: \Leetcode\374.Guess Number Higher or Lower.cpp
 */
/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

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
MEMORY: 5.8MB    BEAT:  82.19%    O(n) = 
USED TIME: 02:18
LAST EDIT TIME: 2021年3月31日10:5:51
Description: 二分。弱智。
*/

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (guess(mid) == 0) return mid;
            if (guess(mid) == 1) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};
// @lc code=end

