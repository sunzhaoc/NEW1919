/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-01 09:42:07
 * @LastEditTime: 2021-03-01 09:48:56
 * @FilePath: \Leetcode\70.Climbing Stairs.cpp
 */
/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
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
TIME:     0ms    BEAT: 100.00%    O(n) = n
MEMORY: 5.9MB    BEAT:  71.76%    O(n) = n
LAST EDIT TIME: 2021年3月1日9:48:48
Description: DP
*/

class Solution {
public:
    int climbStairs(int n) {
        int arr[n + 1];
        arr[0] = 1; 
        arr[1] = 1;
        for (int i = 2; i <= n; i ++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
    }
};

// @lc code=end

