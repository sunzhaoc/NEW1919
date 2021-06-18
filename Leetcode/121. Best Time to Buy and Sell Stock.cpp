/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-02 09:00:21
 * @LastEditTime: 2021-03-02 09:14:59
 * @FilePath: \Leetcode\121.Best Time to Buy and Sell Stock.cpp
 */
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
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
TIME:    140ms    BEAT: 33.34%    O(n) = n
MEMORY: 91.1MB    BEAT: 20.45%    O(n) = 1
LAST EDIT TIME: 2021年3月2日9:14:18
Description: DP空间优化。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pre_dp = 0, dp = 0;
        int minprice = prices[0];
        for (int i = 1; i < prices.size(); i ++) {
            dp = max(pre_dp, prices[i] - minprice);
            minprice = min(minprice, prices[i]);
            pre_dp = dp;
        }
        return dp;
    }
};


/*
RESULT: Accept
TIME:    128ms    BEAT: 48.80%    O(n) = n
MEMORY: 91.6MB    BEAT: 10.35%    O(n) = n
USED TIME: 08:26
LAST EDIT TIME: 2021年3月2日9:10:50
Description: DP
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[prices.size()];
        dp[0] = 0;
        int minprice = prices[0];
        for (int i = 1; i < prices.size(); i ++) {
            dp[i] = max(dp[i - 1], prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }
        return dp[prices.size() - 1];
    }
};


/*
RESULT: Time Out
LAST EDIT TIME: 2021年3月2日9:10:21
Description: 
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 0; i < prices.size() - 1; i ++) {
            for (int j = i + 1; j < prices.size(); j ++) {
                ans = prices[j] - prices[i] > ans ? prices[j] - prices[i] : ans;
            }
        }
        return ans;
    }
};

// @lc code=end

