/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2020-12-01 09:37:48
 * @LastEditTime: 2021-03-17 19:38:36
 * @FilePath: \Leetcode\34.Find First and Last Position of Element in Sorted Array.cpp
 */
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
TIME:      8ms    BEAT: 88.62%    O(n) = 
MEMORY: 13.3MB    BEAT: 78.22%    O(n) = 
USED TIME: 05:25
LAST EDIT TIME: 2021年3月17日19:38:35
Description: 二刷。
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        // Find Left
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] != target) return {-1, -1};
        vector<int> res(2);
        res[0] = l;

        // Find right
        l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (r - l + 1) / 2 + l;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }

        res[1] = r;
        return res;
    }
};


/*
RESULT: Accept
TIME:     20ms    BEAT: %    O(n) = 
MEMORY: 13.7MB    BEAT: %    O(n) = 
LAST EDIT TIME: 2020年12月1日10:45:34
Description: 二分。
*/

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         if (nums.size() == 0){
//             return {-1, -1};
//         }
//         int left = 0, right = nums.size() - 1, mid = 0;
        
//         while (left < right)
//         {
//             mid = (right - left) / 2 + left;
//             if (nums[mid] < target)
//             {
//                 left = mid + 1;
//             }
//             else
//             {
//                 right = mid;
//             }
//         }
//         if (nums[left] != target)
//         {
//             return {-1, -1};
//         }            

//         int leftIdx = left;
//         // return {leftIdx, right};
//         // int left = left;
//         right = nums.size() - 1;

//         while (left < right)
//         {
//             mid = (right - left + 1) / 2 + left;
//             if (nums[mid] > target)
//             {
//                 right = mid - 1;
//             }
//             else
//             {
//                 left = mid;
//             }
//         }
//         return {leftIdx, right};
//     }
// };
// @lc code=end

