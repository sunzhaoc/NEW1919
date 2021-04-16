/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-18 22:04:37
 * @LastEditTime: 2021-03-18 20:56:09
 * @FilePath: \Leetcode\525.Contiguous Array.cpp
 */
/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:    144ms    BEAT: 76.40%    O(n) = 
MEMORY: 76.9MB    BEAT: 76.40%    O(n) = 
USED TIME: 06:08
LAST EDIT TIME: 2021年3月18日20:55:45
Description: 二刷
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 0) nums[i] = -1;
        }

        unordered_map<int, int> map;

        map[0] = -1;
        int max_len = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];

            auto it = map.find(sum);
            if (it != map.end()) {
                max_len = max(max_len, i - it->second);
            }
            else {
                map[sum] = i;
            }
        }
        return max_len;
    }
};


/*
RESULT: Accept
TIME:   124ms    BEAT: 99.80%    O(n) = n
MEMORY:  77MB    BEAT: 93.18%    O(n) = 1
LAST EDIT TIME: 2021年1月19日10:3:0
Description: 前缀和。把所有的0都换成-1，这个方法有点妙。
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }

        int max_len = 0;

        unordered_map<int, int> map;
        map[0] = -1;

        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];

            auto it = map.find(sum);
            if (it != map.end()) {
                max_len = max(max_len, i - it->second);
            }
            else {
                map[sum] = i;
            }
        }

        return max_len;
    }
};


int main() {
    Solution sol;
    // vector<int> nums = {0,1};
    // vector<int> nums = {0,1,0};
    // vector<int> nums = {1,1,1,1,1,1,0,1,0,1,0};
    vector<int> nums = {1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0};
    int ans = sol.findMaxLength(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

