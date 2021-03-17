/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-17 19:09:04
 * @LastEditTime: 2021-03-17 19:26:50
 * @FilePath: \Leetcode\69.Sqrt(x).cpp
 */
/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
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
TIME:     4ms    BEAT: 57.05%    O(n) = 
MEMORY: 5.8MB    BEAT: 60.82%    O(n) = 
LAST EDIT TIME: 2021年3月17日19:25:12
Description: 二分。
*/

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (mid * mid >= x) r = mid;
            else l = mid + 1;
        }
        if (l * l > x) return l - 1;
        else return l;
    }
};


/*
RESULT: Accept
TIME:    24ms    BEAT:  8.58%    O(n) = 
MEMORY: 5.8MB    BEAT: 79.93%    O(n) = 
USED TIME: 02:43
LAST EDIT TIME: 2021年3月17日19:14:58
Description: 
*/

class Solution {
public:
    int mySqrt(int x) {
        long pre = -1;
        for (long i = 0; i <= x; i ++) {
            if (i * i == x) return i;
            else if (i * i > x) return pre;
            else {
                pre = i;
            }
        }
        return -1;
    }
};

// @lc code=end

