/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-20 22:22:41
 * @LastEditTime: 2021-03-23 15:48:36
 * @FilePath: \Leetcode\1798.Maximum Number of Consecutive Values You Can Make.cpp
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
TIME:   120ms    BEAT: 98.33%    O(n) = 
MEMORY:  65MB    BEAT: 81.64%    O(n) = 
LAST EDIT TIME: 2021年3月23日15:39:54
Description: Y总。
*/

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int res = 0;
        for (auto x: coins) {
            if (x > res + 1) break;
            res += x;
        }
        return res + 1;
    }
};


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