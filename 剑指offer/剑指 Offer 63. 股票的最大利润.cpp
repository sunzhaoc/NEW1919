/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-07 14:30:10
 * @LastEditTime: 2021-01-07 14:45:21
 * @FilePath: \Leetcode\剑指 Offer 63. 股票的最大利润.cpp
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:   16ms    BEAT: 31.39%    O(n) = n
MEMORY: 13MB    BEAT: 52.71%    O(n) = 1
USED TIME: 09:45
Description: 空间优化。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int yesterday = 0;
        int nowday;
        int minPrice = prices[0];

        for (int i = 1; i < prices.size(); i ++) {
            nowday = max(yesterday, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
            yesterday = nowday;
        }

        return nowday;
    }
};


/*
RESULT: Accept
TIME:     12ms    BEAT: 67.21%    O(n) = 
MEMORY: 13.1MB    BEAT: 10.65%    O(n) = 
USED TIME: 09:45
Description: 
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        
        vector<int> dp(prices.size(), 0);
        int minPrice = prices[0];

        for (int i = 1; i < prices.size(); i ++) {
            dp[i] = max(dp[i - 1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return dp[dp.size() - 1];
    }
};


int main() {
    Solution sol;
    ans = sol.();
    cout << ans << endl;
    system("pause");
    return 0;
}

