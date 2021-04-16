/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-08 20:32:04
 * @LastEditTime: 2021-03-08 20:56:20
 * @FilePath: \Leetcode\1009.Complement of Base 10 Integer.cpp
 */
/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 5.8MB    BEAT:  84.77%    O(n) = 
USED TIME: 
LAST EDIT TIME: 
Description: 
*/

class Solution {
public:
    int bitwiseComplement(int N) {
        int res = 0, t = 0;
        while (N) {
            res += !(N & 1) << t;
            N >>= 1;
            t ++;
        }
        return res;
    }
};
// @lc code=end

