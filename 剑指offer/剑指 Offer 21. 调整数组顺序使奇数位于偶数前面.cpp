/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-24 10:47:36
 * @LastEditTime: 2020-12-24 13:01:19
 * @FilePath: \Leetcode\剑指 Offer 21. 调整数组顺序使奇数位于偶数前面.cpp
 */

#include <vector>
#include <iostream>
using namespace std;

/*
RESULT: Accept
TIME:     44ms    BEAT: 48.31%    O(n) = 
MEMORY: 18.1MB    BEAT: 38.97%    O(n) = 
Description: 快慢双指针。
https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/solution/ti-jie-shou-wei-shuang-zhi-zhen-kuai-man-shuang-zh/
*/

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int low = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] % 2 == 1) {
                swap(nums[fast], nums[low]);
                low ++;
            }
            fast ++;
        }
        return nums;
    }
};


/*
RESULT: Accept
TIME:   32ms    BEAT: 97.86%    O(n) = 
MEMORY: 18MB    BEAT: 54.82%    O(n) = 
Description: 本题要求在原数组中更改，故不能开辟新空间。使用首尾双指针。
*/

// class Solution {
// public:
//     vector<int> exchange(vector<int>& nums) {
//         int left = 0, right = nums.size() - 1;
        
//         while (left < right) {
//             if (nums[left] % 2 == 0 && nums[right] % 2 == 1)    swap(nums[left], nums[right]);
//             if (nums[left] % 2 == 1)    left ++;
//             if (nums[right] % 2 == 0)   right --;
//         }
//         return nums;
//     }
// };


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = sol.exchange(nums);
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}