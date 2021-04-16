/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-21 11:27:17
 * @LastEditTime: 2021-03-21 11:39:43
 * @FilePath: \Leetcode\demo4.cpp
 */

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


class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i + 1; j < nums.size(); j ++) {
                int tmp = nums[i] ^ nums[j];
                if (tmp >= low && tmp <= high) res ++;
                if (tmp << 1 > high) break;
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {9,8,4,2,1};
    int ans = sol.countPairs(nums, 5, 14);
    // vector<int> nums = {1,4,2,7};
    // int ans = sol.countPairs(nums, 2, 6);
    cout << ans << endl; 
    system("pause");
    return 0;
}
