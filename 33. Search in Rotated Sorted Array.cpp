/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-03 12:59:06
 * @LastEditTime: 2021-03-03 14:47:19
 * @FilePath: \Leetcode\33.Search in Rotated Sorted Array.cpp
 */
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
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
using namespace std;


/*
RESULT: Accept
TIME:      8ms    BEAT: 44.67%    O(n) = logn
MEMORY: 10.9MB    BEAT: 54.50%    O(n) = 1
USED TIME: 04:11
LAST EDIT TIME: 2021年3月3日14:1:3
Description: 二分查找。整理后的Code。
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1, mid;
        while (L <= R) {
            mid = (R - L) / 2 + L;
            if (nums[mid] == target) return mid;
            
            // 左边是有序的
            if (nums[L] <= nums[mid]) {
                // 并且target在前半部分 --> nums[left] <= target <= nums[mid]
                if (nums[L] <= target && target <= nums[mid]) R = mid - 1;
                else L = mid + 1;
            }

            // 右边是有序的
            else {
                // 并且targer在后半部分。 --> nums[mid] <= target <= nums[right]
                if (nums[mid] <= target && target <= nums[R]) L = mid + 1;
                else R = mid - 1;
            }
        }
        return -1;
    }
};


/*
RESULT: Accept
TIME:      0ms    BEAT: 100.00%    O(n) = logn
MEMORY: 10.9MB    BEAT:  52.08%    O(n) = 1
USED TIME: 26:58
LAST EDIT TIME: 2021年3月3日13:35:50
Description: 二分查找。
取中间mid，判断左右哪个是有序的，在有序的当中查找。
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int L = 0, R = nums.size() - 1;
        int mid, index;
        while (L <= R) {
            mid = (R - L) / 2 + L;
            if (nums[L] < nums[mid]) {
                index = binaryResearch(nums, L, mid, target);
                if (index != -1) return index;
                else {
                    L = mid + 1;
                }
            }
            else if (nums[mid] < nums[R]) {
                index = binaryResearch(nums, mid, R, target);
                if (index != -1) return index;
                else {
                    R = mid - 1;
                }
            }
            else {
                if (nums[L] == target) return L;
                if (nums[R] == target) return R;
                return -1;
            }
        }
        return -1;
    }

    int binaryResearch(vector<int>& nums, int left, int right, int target) {
        int mid;
        while(left <= right) {
            mid = (right - left) / 2 + left;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};


/*
RESULT: Accept
TIME:      8ms    BEAT: 44.67%    O(n) = n
MEMORY: 10.7MB    BEAT: 93.48%    O(n) = 1
USED TIME: 03:34
LAST EDIT TIME: 2021年3月3日13:4:34
Description: 遍历一遍数组。只是没想到不会超时。
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == target) return i;
        }
        return -1;
    }
};


int main() {
    Solution sol;
    // vector<int> nums = {4,5,6,7,0,1,2};
    // int ans = sol.search(nums, 3);
    vector<int> nums = {1,3};
    int ans = sol.search(nums, 3);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

