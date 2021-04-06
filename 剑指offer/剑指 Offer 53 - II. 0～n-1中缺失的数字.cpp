/*
 * @Description: 
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-12-03 22:29:07
 * @LastEditTime: 2020-12-03 22:43:42
 * @FilePath: \Leetcode\剑指 Offer 53 - II. 0～n-1中缺失的数字.cpp
 */

/*
RESULT: Accept
TIME: 32ms BEAT: 95.24%
MEMORY: 17.2MB BEAT: 16.24%
Description: 二分法
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        while (l < r)
        {
            int mid = (r - l) / 2 + l;

            if (nums[mid] == mid)   l = mid + 1;
            else r = mid;
        }

        if (nums[l] == l) return ++l;
        else return l;
    }
};