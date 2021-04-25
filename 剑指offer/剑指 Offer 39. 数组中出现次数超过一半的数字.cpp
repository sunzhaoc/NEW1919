/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-24 14:52:46
 * @LastEditTime: 2020-12-24 15:31:20
 * @FilePath: \Leetcode\剑指 Offer 39. 数组中出现次数超过一半的数字.cpp
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:     44ms    BEAT: 70.57%    O(n) = n
MEMORY: 18.8MB    BEAT: 26.05%    O(n) = 1
Description: 摩尔投票法。
https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/solution/mian-shi-ti-39-shu-zu-zhong-chu-xian-ci-shu-chao-3/
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0, ans;
        for (int num: nums) {
            if (vote == 0)  ans = num;
            vote += num == ans ? 1 : -1;
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:    104ms    BEAT:  5.34%    O(n) = n
MEMORY: 18.9MB    BEAT: 12.33%    O(n) = n
Description: 哈希表。
*/

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> dic;
//         for (int i = 0; i < nums.size(); i ++) {
//             dic[nums[i]] ++;
//             if (dic[nums[i]] > nums.size() / 2) return nums[i];
//         }
//         return NULL;
//     }
// };


int main() {
    Solution sol;
    // vector<int> nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    vector<int> nums = {10, 9, 9, 9, 10};
    int ans = sol.majorityElement(nums);
    cout << ans << endl;
    system("pause");
    return 0;
}