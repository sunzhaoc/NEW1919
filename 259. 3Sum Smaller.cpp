/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-14 21:07:09
 * @LastEditTime: 2021-01-14 21:34:02
 * @FilePath: \Leetcode\259.3Sum Smaller.cpp
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
TIME:     12ms    BEAT:  96.82%    O(n) = n^2
MEMORY: 12.7MB    BEAT: 100.00%    O(n) = logn
USED TIME: 21:42
LAST EDIT TIME: 2021年1月14日21:32:19
Description: 双指针。
*/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        sort(nums.begin(), nums.end());

        for (int first = 0; first < nums.size(); first ++) {
            int second = first + 1;
            int third = nums.size() - 1;

            while (second < third) {
                if (nums[first] + nums[second] + nums[third] < target) {
                    count += (third - second); // 难点：就离谱。
                    second ++;
                }
                else {
                    third --;
                }
            }
        }
        return count;
    }
};


int main() {
    Solution sol;
    // vector<int> nums = {-2,0,1,3}; int target = 2;
    vector<int> nums = {3,1,0,-2}; int target = 4;
    int  ans = sol.threeSumSmaller(nums, target);
    cout << ans << endl; 
    system("pause");
    return 0;
}

