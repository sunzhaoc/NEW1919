/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-09 19:40:31
 * @LastEditTime: 2021-03-09 20:15:38
 * @FilePath: \Leetcode\371.Sum of Two Integers.cpp
 */
/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 5.9MB    BEAT:  51.27%    O(n) = 
LAST EDIT TIME: 2021年3月9日20:4:13
Description: 
*/

class Solution {
public:
    int getSum(int a, int b) {
        return !(a & b) ? a ^ b : getSum(a ^ b, ((unsigned int)(a & b)) << 1);
    }
};

// @lc code=end

