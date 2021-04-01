/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-01 16:39:15
 * @LastEditTime: 2021-04-01 16:50:35
 * @FilePath: \Leetcode\1281.Subtract the Product and Sum of Digits of an Integer.cpp
 */
/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
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
TIME:     0ms    BEAT: 100.00%    O(n) = n
MEMORY: 5.8MB    BEAT:  80.39%    O(n) = 1
USED TIME: 01:24
LAST EDIT TIME: 2021年4月1日16:50:18
Description: 二刷。Python before. Easy.
*/

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, product = 1;
        while (n) {
            sum += n % 10;
            product *= n % 10;
            n /= 10;
        }
        return product - sum;
    }
};
// @lc code=end

