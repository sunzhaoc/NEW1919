/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-15 17:17:46
 * @LastEditTime: 2021-03-15 21:23:43
 * @FilePath: \Leetcode\1793.Maximum Score of a Good Subarray.cpp
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


/*
RESULT: Accept
TIME:    188ms    BEAT: 100.00%    O(n) = 
MEMORY: 87.4MB    BEAT: 100.00%    O(n) = 
LAST EDIT TIME: 2021年3月15日21:18:14
Description: 应该是第11题的加强版。
*/

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int L = k, R = k;
        int n = nums.size();
        int res = 0;

        while (1) {
            while (R < n && nums[R] >= nums[k]) R ++;
            while (L >= 0 && nums[L] >= nums[k]) L --;
            res = max(res, ((R - 1) - (L + 1) + 1) * nums[k]);
            
            if (L < 0 && R == n) break;
            if (L >= 0 && R < n) nums[k] = max(nums[L], nums[R]);
            else if (L < 0) nums[k] = nums[R];
            else nums[k] = nums[L];
        }
        
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {6569,9667,3148,7698,1622,2194,793,9041,1670,1872};
    int ans = sol.maximumScore(nums, 5);
    // vector<int> nums = {5,5,4,5,4,1,1,1};
    // int ans = sol.maximumScore(nums, 0);
    cout << ans << endl;
    system("pause");
    return 0;
}

