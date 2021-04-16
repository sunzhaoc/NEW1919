/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-08 15:10:25
 * @LastEditTime: 2021-03-08 15:22:02
 * @FilePath: \Leetcode\977.Squares of a Sorted Array.cpp
 */
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
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
TIME:     32ms    BEAT: 92.82%    O(n) = m + n
MEMORY: 25.3MB    BEAT: 74.15%    O(n) = n
USED TIME: 04:16
LAST EDIT TIME: 
Description: 
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j; ) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                i ++;
            }
            else {
                ans[pos] = nums[j] * nums[j];
                j --;
            }
            pos --;
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:     40ms    BEAT: 76.72%    O(n) = nlogn
MEMORY: 25.2MB    BEAT: 86.75%    O(n) = logn
USED TIME: 01:15
LAST EDIT TIME: 2021年3月8日15:14:32
Description: 
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++) {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// @lc code=end

