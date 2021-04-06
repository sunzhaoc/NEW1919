/*
 * @Description:  
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-30 16:28:56
 * @LastEditTime: 2021-04-06 08:51:55
 * @FilePath: \Leetcode\80.Remove Duplicates from Sorted Array II.cpp
 */
/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
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
TIME:      8ms    BEAT: 57.79%    O(n) = n
MEMORY: 10.7MB    BEAT: 14.29%    O(n) = 1
USED TIME: 26:06
LAST EDIT TIME: 2021年4月6日8:51:33
Description: 二刷。
有思路，不过还是卡住了。
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int id = 1;
        int cnt = 1;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] != nums[i - 1]) cnt = 1;
            else cnt ++;
            if (cnt <= 2) {
                nums[id++] = nums[i];
            }
        }
        return id;
    }
};


/*
RESULT: Accept
TIME:      0ms    BEAT: 100.00%    O(n) = n
MEMORY: 10.7MB    BEAT:  89.08%    O(n) = 1
LAST EDIT TIME: 2021年1月30日18:17:19
Description: 双指针。值得想一想。
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() <= 2) return nums.size();
        int left = 1, right = 2;
        while (right <= nums.size() - 1) {
            if (nums[left - 1] == nums[right]) {
                right ++;
            }
            else {
                nums[++left] = nums[right];
                right ++;
            }
        }
        return left + 1;
    }
};


/*
RESULT: Accept
TIME:     12ms    BEAT: 53.30%    O(n) = n
MEMORY: 11.2MB    BEAT:  5.04%    O(n) = n
LAST EDIT TIME: 2021年1月30日16:52:44
Description: 开辟了一个哈希表的空间。
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int left = 0, right = nums.size() - 1;
        unordered_map<int, int> map;
        while (left <= right) {
            if (map[nums[left]] < 2) {
                map[nums[left]] ++;
                left ++;
            }
            else {
                swap(nums[left], nums[right]);
                right --;
            }
        }
        sort(nums.begin(), nums.begin() + right + 1);
        return right + 1;
    }
};
// @lc code=end

