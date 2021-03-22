/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-20 22:22:41
 * @LastEditTime: 2021-03-21 10:18:34
 * @FilePath: \Leetcode\5712.Maximum Number of Consecutive Values You Can Make.cpp
 */
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
TIME:   192ms    BEAT: 100.00%    O(n) = 
MEMORY:  65MB    BEAT: 100.00%    O(n) = 
LAST EDIT TIME: 2021-03-20 23:19:40
Description: 
*/

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        
        sort(coins.begin(), coins.end());
        if (coins[0] != 1) return 1;
        // vector<int> dp(coins.size() + 1);
        int dp = 0;
        for (int i = 0; i < coins.size(); i ++) {
            if (coins[i] + dp >= dp + 1 && coins[i] <= dp + 1) {
                dp += coins[i];
            }
            else return dp + 1;
        }
        return dp + 1;
        
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1,1,1,4};
    // vector<int> nums = {1,4,10,3,1};
    // vector<int> nums = {1,3};
    int ans = sol.getMaximumConsecutive(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}