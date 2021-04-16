/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-24 09:02:29
 * @LastEditTime: 2021-03-24 10:58:52
 * @FilePath: \Leetcode\458.Poor Pigs.cpp
 */
/*
 * @lc app=leetcode.cn id=458 lang=cpp
 *
 * [458] 可怜的小猪
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
TIME:     0ms    BEAT: 100.00%    O(n) = logn
MEMORY: 5.8MB    BEAT:  92.02%    O(n) = 1
LAST EDIT TIME: 2021年3月24日10:55:22
Description: Y总的代码。具体的步骤见笔记。有点难想。是很难想~！~~~~~！！！！
-->提炼：每头猪可以表示minutesToTest / minutesToDie + 1种状态，总共有buckets种状态，问需要多少头猪。
*/

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int b = minutesToTest / minutesToDie + 1;
        int k = 0, n = 1;
        while (n < buckets) k ++, n *= b;
        return k;
    }
};

// @lc code=end

