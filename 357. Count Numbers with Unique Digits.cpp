/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-07 14:11:29
 * @LastEditTime: 2021-04-07 14:56:20
 * @FilePath: \Leetcode\357.Count Numbers with Unique Digits.cpp
 */
/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;


/*
RESULT: Accept
TIME:      0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.1iMB    BEAT:  21.58%    O(n) = 
LAST EDIT TIME: 2021年4月7日14:56:13
Description: 
https://leetcode-cn.com/problems/count-numbers-with-unique-digits/solution/cbiao-ge-jie-shi-shu-xue-si-lu-die-dai-ac-by-monol/
不会啊。数学知识。
*/

typedef long long LL;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n < 2) return pow(10, n);
        LL cur = 9, ans = 10, tmp = 9;
        for (int i = 2; i <= n; i ++) {
            cur = cur * tmp --;
            ans = ans + cur;
            if (tmp == 0) break;
        }
        return ans;
    }
};
// @lc code=end

