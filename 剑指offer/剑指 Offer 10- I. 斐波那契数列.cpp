/*
 * @Description: 
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-12-10 16:03:45
 * @LastEditTime: 2020-12-10 16:23:44
 * @FilePath: \Leetcode\剑指 Offer 10- I. 斐波那契数列.cpp
 */


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = n
MEMORY: 6.2MB    BEAT:  25.71%    O(n) = 1
Description: 
*/

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int a = 0, b = 1, c = 0;

        for (int i = 2; i <= n; i ++) {
            c = (a + b) % 1000000007;
            a = b;
            b = c;
        }
        
        return c;
    }
};
