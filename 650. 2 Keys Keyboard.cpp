/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-24 09:03:05
 * @LastEditTime: 2021-03-24 19:41:45
 * @FilePath: \Leetcode\650.2 Keys Keyboard.cpp
 */
/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 5.8MB    BEAT:  83.97%    O(n) = 
LAST EDIT TIME: 2021年3月24日19:25:34
Description: 不会。没思路。Y总的。
*/

class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        for (int i = 2; n > 1; i++) {
            while (n % i == 0) {
                res += i; 
                n /= i;
            }
        }
        return res;
    }
};
// @lc code=end

