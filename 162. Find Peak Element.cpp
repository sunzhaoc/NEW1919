/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-17 19:09:56
 * @LastEditTime: 2021-03-30 19:59:16
 * @FilePath: \Leetcode\162.Find Peak Element.cpp
 */
/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 8.4MB    BEAT:  98.58%    O(n) = 
LAST EDIT TIME: 2021年3月17日21:3:32
Description: 二分。
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int mid;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            mid = (r - l) / 2 + l;
            if (nums[mid] > nums[mid + 1]) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};


/*
RESULT: Wrong
LAST EDIT TIME: 2021年3月17日20:39:16
Description: 又出现BUG了？vscode能运行，leetcode报错。
*/

// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         if (nums.size() == 1) return 0;
//         int l = 0, r = nums.size() - 1;
//         while (l <= r) {
//             int mid = (r - l) / 2 + l;
//             if ((nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) || (mid == 0 && nums[mid] > nums[mid + 1]) || (mid == nums.size() - 1 && nums[mid] > nums[mid - 1])) return mid;
//             else if (nums[mid] > nums[mid + 1] && nums[mid] < nums[mid - 1]) r = mid - 1;
//             else l = mid + 1;
//         }
//         return -1;
//     }
// };


/*
RESULT: Accept
TIME:     4ms    BEAT: 90.58%    O(n) = 
MEMORY: 8.5MB    BEAT: 91.64%    O(n) = 
USED TIME: 05:21
LAST EDIT TIME: 2021年3月17日20:22:57
Description: 
*/

// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         if (nums.size() == 1) return 0;
//         if (nums[0] > nums[1]) return 0;
//         for (int i = 1; i < nums.size() - 1; i ++) {
//             if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
//         }
//         if (nums.back() > nums[nums.size() - 2]) return nums.size() - 1;
//         return -1;
//     }
// };


int main() {
    Solution sol;
    // vector<int> nums = {2, 1};
    vector<int> nums = {1,2,1,3,5,6,4};
    int ans = sol.findPeakElement(nums);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

