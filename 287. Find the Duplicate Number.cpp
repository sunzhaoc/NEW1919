/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-30 19:27:35
 * @LastEditTime: 2021-03-31 09:35:58
 * @FilePath: \Leetcode\287.Find the Duplicate Number.cpp
 */
/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
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
TIME:      4ms    BEAT: 97.93%    O(n) = 
MEMORY: 10.7MB    BEAT: 57.61%    O(n) = 
LAST EDIT TIME: 2021年3月31日9:25:31
Description: 抽屉原理。y总。原地算法。
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 1, r = n; // 这里的区间不是下标，而是表示数1 到 n-1。
        while (l < r) {
            int mid = (r - l) / 2 + l;
            int cnt = 0;
            for (auto x: nums) {
                if (x >= l && x <= mid) cnt ++;
            }
            if (cnt > mid - l + 1) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};


/*
RESULT: Accept
TIME:     12ms    BEAT: 58.22%    O(n) = 
MEMORY: 10.8MB    BEAT: 44.50%    O(n) = 
USED TIME: 16:32
LAST EDIT TIME: 2021年3月30日19:46:2
Description: my idea is：判断左右区间哪个更紧密。数字分布更紧密的区间
即(nums[i] - nums[j]) / (i - j) 更小，则重复的数处于这一区间。
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] == nums[r] || nums[mid] == nums[l]) return nums[mid];
            if ((nums[mid] - nums[l]) / (mid - l) > (nums[r] - nums[mid]) / (r - mid)) l = mid;
            else r = mid;
        }
        return -1;
    }
};

// @lc code=end

