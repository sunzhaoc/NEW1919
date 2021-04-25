/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-03 08:28:29
 * @LastEditTime: 2021-03-03 09:01:51
 * @FilePath: \Leetcode\338.Counting Bits.cpp
 */
/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
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
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 96.36%    O(n) = n
MEMORY: 7.8MB    BEAT: 64.39%    O(n) = n
LAST EDIT TIME: 2021年3月3日9:1:56
Description: 布赖恩·克尼根算法 + DP
https://leetcode-cn.com/problems/counting-bits/solution/c-bu-lai-en-ke-ni-gen-suan-fa-dong-tai-g-17ym/
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        for (int i = 1; i <= num; i ++) {
            ans[i] = ans[i & (i - 1)] + 1;
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = n
MEMORY: 7.7MB    BEAT:  77.60%    O(n) = n
LAST EDIT TIME: 2021年3月3日8:34:6
Description: 这种才是正解，并不需要位运算。
对于所有数字只有两类：
1、奇数：奇数一定比前面那个偶数多一个 1，因为多的就是最低位的 1。
2、偶数：偶数中 1 的个数一定和除以 2 之后的那个数一样多。
https://leetcode-cn.com/problems/counting-bits/solution/hen-qing-xi-de-si-lu-by-duadua/
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        ans[0] = 0;
        for (int i = 1; i <= num; i ++) {
            if (i % 2 == 1) {
                ans[i] = ans[i - 1] + 1;
            }
            else ans[i] = ans[i / 2];
        }
        return ans;
    }
};

// @lc code=end

