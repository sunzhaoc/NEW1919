/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-09 14:18:33
 * @LastEditTime: 2021-03-09 14:47:42
 * @FilePath: \Leetcode\75.Sort Colors.cpp
 */
/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
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
TIME:     4ms    BEAT: 52.86%    O(n) = 
MEMORY: 8.1MB    BEAT: 53.02%    O(n) = 
LAST EDIT TIME: 2021年3月9日14:47:19
Description: 双指针。
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size() - 1;
        for (int i = 0; i <= p2; i ++) {
            while (i <= p2 && nums[i] == 2) {
                swap(nums[i], nums[p2]);
                p2 --;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                p0 ++;
            }
        }
    }
};



/*
RESULT: Accept
TIME:   4ms    BEAT: 52.86%    O(n) = n
MEMORY: 8MB    BEAT: 75.58%    O(n) = 1
USED TIME: 02:46
LAST EDIT TIME: 2021年3月9日14:25:43
Description: 先统计每个颜色的个数。
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int map[3] = {0, 0, 0};
        for (int num: nums) {
            map[num] ++;
        }
        for (int i = 0; i < map[0]; i ++) {
            nums[i] = 0;
        }
        for (int i = map[0]; i < map[0] + map[1]; i ++) {
            nums[i] = 1;
        }
        for (int i = map[0] + map[1]; i < nums.size(); i ++) {
            nums[i] = 2;
        }
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = nlogn
MEMORY: 8.1MB    BEAT:  54.90%    O(n) = logn
USED TIME: 00:45
LAST EDIT TIME: 2021年3月9日14:20:40
Description: 干嘛不用sort？我又不傻。
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

// @lc code=end

