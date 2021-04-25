/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-24 09:02:41
 * @LastEditTime: 2021-03-24 18:11:35
 * @FilePath: \Leetcode\319.Bulb Switcher.cpp
 */
/*
 * @lc app=leetcode.cn id=319 lang=cpp
 *
 * [319] 灯泡开关
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
TIME:     0ms    BEAT: 100.00%    O(n) = 1
MEMORY: 5.7MB    BEAT:  89.74%    O(n) = 1
LAST EDIT TIME: 2021年3月24日17:56:37
Description: 不会。Y总的思路。
每个灯被按的次数等于其约数的个数 ---> 求1-n中约数个数为奇数的数的个数 --> 只有平方数的约数个数为奇数
*/

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
// @lc code=end

