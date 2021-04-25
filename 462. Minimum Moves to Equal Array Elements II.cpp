/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-24 09:02:15
 * @LastEditTime: 2021-03-24 10:12:12
 * @FilePath: \Leetcode\462.Minimum Moves to Equal Array Elements II.cpp
 */
/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最少移动次数使数组元素相等 II
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
TIME:      8ms    BEAT: 97.59%    O(n) = n
MEMORY: 10.3MB    BEAT: 54.92%    O(n) = 1
LAST EDIT TIME: 2021年3月24日10:10:50
Description: Y总的代码。
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());    // 可以在复杂度为n的情况下找到第n小的数。
        int x = nums[n / 2];
        
        int res = 0;
        for (int i: nums) res += abs(x - i);
        return res;
    }
};


/*
RESULT: Accept
TIME:     12ms    BEAT: 82.19%    O(n) = nlogn
MEMORY: 10.2MB    BEAT: 91.09%    O(n) = logn
USED TIME: 02:15
LAST EDIT TIME: 2021年3月24日9:53:11
Description: 我是没想到这么Easy就过了。就是求一个中位数。。。
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target = nums[nums.size() / 2];
        long long res = 0;
        for (int x: nums) res += abs(target - x);
        return res;
    }
};

// @lc code=end

