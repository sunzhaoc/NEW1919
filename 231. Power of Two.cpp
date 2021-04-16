/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-04 20:27:27
 * @LastEditTime: 2021-03-04 21:15:38
 * @FilePath: \Leetcode\231.Power of Two.cpp
 */
/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start


/*
RESULT: Accept
TIME:     4ms    BEAT: 43.53%    O(n) = 1
MEMORY: 5.8MB    BEAT: 82.30%    O(n) = 1
LAST EDIT TIME: 2021年3月4日21:15:37
Description: x&(-x)表示x的二进制表示里最右边的一个1，如果n是2的倍数，则必然只有1个1，所以它们相等。
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & -n) == n;
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 43.53%    O(n) = 1
MEMORY: 5.7MB    BEAT: 97.53%    O(n) = 1
LAST EDIT TIME: 2021年3月4日20:42:33
Description: Y总。
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && ((1 << 30) % n == 0);
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 43.53%    O(n) = logn
MEMORY: 5.7MB    BEAT: 86.13%    O(n) = 1
USED TIME: 04:28
LAST EDIT TIME: 2021年3月4日20:33:12
Description: 
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n != 1) {
            if (n % 2 == 1) return false;
            n /= 2;
        }
        return true;
    }
};

// @lc code=end

