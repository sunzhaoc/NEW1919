/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-03 09:06:04
 * @LastEditTime: 2021-03-03 10:30:14
 * @FilePath: \Leetcode\31.Next Permutation.cpp
 */
/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
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
TIME:      4ms    BEAT: 85.05%    O(n) = 
MEMORY: 11.9MB    BEAT: 48.87%    O(n) = 
LAST EDIT TIME: 2021年3月3日10:19:1
Description: 脑筋急转弯？？？看解析吧。。。
1、从后向前查找第一个相邻升序的元素对 (i,j)，满足 A[i] < A[j]。此时 [j,end) 必然是降序
2、在 [j,end) 从后向前查找第一个满足 A[i] < A[k] 的 k，将 A[i] 与 A[k] 交换，可以断定这时 [j,end) 必然是降序，逆置 [j,end)，使其升序
如果在步骤 1 找不到符合的相邻元素对，说明当前 [begin,end) 为一个降序顺序，直接反转。
https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return;

        int tmp = -1;
        for (int i = nums.size() - 1; i > 0; i --) {
            if (nums[i] > nums[i - 1]) {
                tmp = i - 1;
                break;
            }
        }
        
        // 找不到一个升序排列，直接反转。
        if (tmp == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int tmp2 = -1;
        for (int i = nums.size() - 1; i >= tmp + 1; i --) {
            if (nums[i] > nums[tmp]) {
                tmp2 = i;
                break;
            }
        }

        swap(nums[tmp], nums[tmp2]);
        reverse(nums.begin() + tmp + 1, nums.end());
    }
};


int main() {
    Solution sol;
    // vector<int> nums = {1, 2, 3};
    // vector<int> nums = {3,2,1};
    vector<int> nums = {1,2,4,5};
    sol.nextPermutation(nums);
    system("pause");
    return 0;
}

// @lc code=end

