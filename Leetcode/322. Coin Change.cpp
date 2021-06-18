/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-11 16:08:02
 * @LastEditTime: 2021-03-11 20:20:09
 * @FilePath: \Leetcode\322.Coin Change.cpp
 */
/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
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
TIME:     96ms    BEAT: 63.33%    O(n) = 
MEMORY: 14.6MB    BEAT: 14.80%    O(n) = 
LAST EDIT TIME: 2021年3月11日16:8:38
Description: 记忆化搜索。草。又是这。
开始的回路就错了，以为用栈，尽可能放最大的数，使用的数量就会最少。举个栗子：
Target = 9
Paper = {6， 4， 1} 
显然 6 + 1 + 1 + 1 > 4 + 4 + 1
所以开始并不需要给其排序。
*/

class Solution {
public:
    vector<int> count;
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < *min_element(coins.begin(), coins.end())) return -1;
        sort(coins.rbegin(), coins.rend());
        count.resize(amount + 1, 0);
        return dfs(coins, amount);
    }
    
    int dfs(vector<int>& coins, int num) {
        // 返回的是张数。
        if (num == 0) return 0;
        if (num < 0) return -1;

        if (count[num] != 0) return count[num];

        int Min = INT_MAX;
        for (int coin: coins) {
            int res = dfs(coins, num - coin);
            if (res >= 0 && res < Min) {
                Min = res + 1;
            }
        }
        count[num] = Min == INT_MAX ? -1 : Min;
        return count[num];
    }
};


int main() {
    Solution sol;
    vector<int> coins = {419, 408, 186, 83};
    int ans = sol.coinChange(coins, 6249);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

