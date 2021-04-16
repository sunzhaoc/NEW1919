/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-14 19:30:15
 * @LastEditTime: 2021-01-14 20:08:49
 * @FilePath: \Leetcode\1099.Two Sum Less Than K.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT:  97.09%    O(n) = nlogn
MEMORY: 8.7MB    BEAT: 100.00%    O(n) = 1
USED TIME: 20:21
LAST EDIT TIME: 2021年1月14日20:8:52
Description: 双指针法。
*/

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) { 
        int l = 0;
        int r = nums.size() - 1;

        sort(nums.begin(), nums.end());
        int sum = 0;

        while (l < r) {
            if (nums[l] + nums[r] >= k) r--;
            if (nums[l] + nums[r] < k) {
                sum = nums[l] + nums[r] > sum ? nums[l] + nums[r] : sum;
                l ++;
            }
        }
        
        return sum ? sum : -1;
    }
};


/*
RESULT: Accept
TIME:     8ms    BEAT: 71.84%    O(n) = n^2
MEMORY: 8.9MB    BEAT: 98.94%    O(n) = 1
USED TIME: 04:00
LAST EDIT TIME: 2021年1月14日19:42:54
Description: 暴力法。
*/

// class Solution {
// public:
//     int twoSumLessThanK(vector<int>& nums, int k) {
//         int sum = 0;

//         for (int i = 0; i < nums.size(); i ++) {
//             for (int j = i + 1; j < nums.size(); j ++) {
//                 if (nums[i] + nums[j] > sum && nums[i] + nums[j] < k)  sum = nums[i] + nums[j];
//             }
//         }
        
//         if (sum == 0) return -1;
//         return sum;
//     }
// };


int main() {
    Solution sol;
    // vector<int> nums = {34,23,1,24,75,33,54,8}; int k = 60;
    // vector<int> nums = {10,20,30}; int k = 15;
    vector<int> nums = {254,914,110,900,147,441,209,122,571,942,136,350,160,127,178,839,201,386,462,45,735,467,153,415,875,282,204,534,639,994,284,320,865,468,1,838,275,370,295,574,309,268,415,385,786,62,359,78,854,944,200}; int k = 200;
    int ans = sol.twoSumLessThanK(nums, k);
    cout << ans << endl;
    system("pause");
    return 0;
}

