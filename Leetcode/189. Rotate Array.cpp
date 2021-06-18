/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-08 13:25:19
 * @LastEditTime: 2021-01-08 14:24:13
 * @FilePath: \Leetcode\189.Rotate Array.cpp
 */
/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start

// 还有一种环状替换的方法，没写。

/*
RESULT: Accept
TIME:     12ms    BEAT: 50.50%    O(n) = n
MEMORY: 10.2MB    BEAT:  8.15%    O(n) = n
USED TIME: 02:58
Description: 最笨的方法。容器的assign方法可以注意一下。
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> newNums(nums.size());
        for (int i = 0; i < nums.size(); i ++) {
            newNums[(i + k) % nums.size()] = nums[i];
        }
        nums.assign(newNums.begin(), newNums.end());
    }
};


/*
RESULT: Accept
TIME:    12ms    BEAT: 50.50%    O(n) = n
MEMORY: 9.9MB    BEAT: 65.29%    O(n) = 1
USED TIME: 05:16
Description: 数组翻转。
*/

class Solution {
public:
    void reverse(vector<int>&nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start ++;
            end --;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);    
    }
};
// @lc code=end

