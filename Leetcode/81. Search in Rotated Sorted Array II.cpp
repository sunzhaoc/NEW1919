/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-30 18:24:57
 * @LastEditTime: 2021-03-03 14:34:49
 * @FilePath: \Leetcode\81.Search in Rotated Sorted Array II.cpp
 */
/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
using namespace std;


/*
RESULT: Accept
TIME:      8ms    BEAT: 52.67%    O(n) = logn
MEMORY: 13.6MB    BEAT: 44.82%    O(n) = 1
LAST EDIT TIME: 2021年3月3日14:32:1
Description: 二刷。从33题转来。思路Get，写No。特别是分不清到底是前面有序还是后面有序的情况。
https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/solution/zai-javazhong-ji-bai-liao-100de-yong-hu-by-reedfan/
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1, mid;
        while (L <= R) {
            mid = (R - L) / 2 + L;
            if (nums[mid] == target) return true;

            if (nums[L] == nums[mid]) {
                L ++;
                continue;
            }
            // 前半部分有序。
            else if (nums[L] <= nums[mid]) {
                // 并且target在前半部分 --> nums[left] <= target <= nums[mid]
                if (target >= nums[L] && target <= nums[mid]) R = mid - 1;
                else L = mid + 1;
            }
            // 后半部分有序。
            else {
                // 并且targer在后半部分。 --> nums[mid] <= target <= nums[right]
                if (target >= nums[mid] && target <= nums[R]) L = mid + 1;
                else R = mid - 1;
            }
        }
        return false;
    }
};


/*
RESULT: Accept
TIME:     12ms    BEAT: 15.17%    O(n) = 
MEMORY: 13.6MB    BEAT: 21.63%    O(n) = 
LAST EDIT TIME: 2021年1月30日21:9:43
Description: 二分查找。边界条件有点难找。
*/

// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         if (nums.size() == 0) return false;

//         int left = 0, right = nums.size() - 1;
//         int mid;
//         while (left <= right) {
//             mid = (right - left) / 2 + left;

//             if (nums[mid] == target) return true;

//             if (nums[left] == nums[mid]) {
//                 left ++;
//                 continue;
//             }

//             // Front
//             if (nums[left] < nums[mid]) {
//                 if (nums[left] <= target && nums[mid] > target) {
//                     right = mid - 1;
//                 }
//                 else {
//                     left = mid + 1;
//                 }
//             }
//             else {
//                 if (target > nums[mid] && target <= nums[right]) {
//                     left = mid + 1;
//                 }
//                 else {
//                     right = mid - 1;
//                 }
//             }
//         }
//         return false;
//     }
// };


int main() {
    Solution sol;
    // vector<int> nums = {4,5,6,7,0,1,2};
    // int ans = sol.search(nums, 3);
    vector<int> nums = {1,2,1};
    int ans = sol.search(nums, 0);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

