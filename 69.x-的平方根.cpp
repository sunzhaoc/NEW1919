/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-17 19:09:04
 * @LastEditTime: 2021-03-17 19:15:17
 * @FilePath: \Leetcode\69.x-的平方根.cpp
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

