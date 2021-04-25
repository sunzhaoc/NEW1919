/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-25 09:10:35
 * @LastEditTime: 2021-03-25 09:19:25
 * @FilePath: \Leetcode\35.Search Insert Position.cpp
 */
/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
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
TIME:     8ms    BEAT: 48.30%    O(n) = 
MEMORY: 9.3MB    BEAT: 90.69%    O(n) = 
USED TIME: 02:58
LAST EDIT TIME: 2021年3月25日9:18:49
Description: 二刷。前一次是python
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (r - l) / 2 + 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] >=  target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] >= target) return l;
        else return l + 1;
    }
};
// @lc code=end

