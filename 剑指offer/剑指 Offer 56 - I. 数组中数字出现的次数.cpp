/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-06 17:00:42
 * @LastEditTime: 2021-01-06 17:10:12
 * @FilePath: \Leetcode\剑指 Offer 56 - I. 数组中数字出现的次数.cpp
 */

#include <iostream>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:     36ms    BEAT: 90.05%    O(n) = 
MEMORY: 16.1MB    BEAT: 43.15%    O(n) = 
Description: 分组异或运算。
*/

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0;

        for (int i: nums) {
            x ^= i;
        }

        int first = 1;
        while (!(first & x)) {
            first <<= 1;
        }
        
        int a = 0, b = 0;
        for (int i: nums) {
            if (i & first) a ^= i;
            else b ^= i;
        }

        return {a, b};
    }
};


int main() {
    Solution sol;
    vector<int> nums = {4, 1, 4, 6};
    vector<int> ans = sol.singleNumbers(nums);
    system("pause");
    return 0;
}


