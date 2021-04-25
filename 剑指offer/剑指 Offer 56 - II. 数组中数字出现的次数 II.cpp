/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-06 17:11:17
 * @LastEditTime: 2021-01-06 17:16:07
 * @FilePath: \Leetcode\剑指 Offer 56 - II. 数组中数字出现的次数 II.cpp
 */

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> binary(32, 0);

        for (int i: nums) {
            for (int j = 31; j >= 1; j --) {
                binary[j] += i & 1;
                i >>= 1;
            }
        }

        int res;

        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {4, 1, 4, 4};
    vector<int> ans = sol.singleNumber(nums);
    system("pause");
    return 0;
}