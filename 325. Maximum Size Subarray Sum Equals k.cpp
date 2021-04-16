/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-16 21:23:10
 * @LastEditTime: 2021-01-16 21:37:31
 * @FilePath: \Leetcode\325.Maximum Size Subarray Sum Equals k.cpp
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
TIME:   44ms    BEAT: 99.53%    O(n) = 
MEMORY: 17MB    BEAT: 97.57%    O(n) = 
USED TIME: 11:09
LAST EDIT TIME: 2021年1月16日21:36:22
Description: 哈希表 + 前缀和。 做烂了。。。
*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = -1; // 这步稍微注意一下。
        int sum = 0;
        int res = 0;
        
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            auto it = map.find(sum - k);
            if (it != map.end()) {
                res = max(res, i - it->second);
            }
            
            it = map.find(sum);
            if (it == map.end()) map[sum] = i;
        }

        return res;
    }
};


int main() {
    Solution sol;
    // vector<int> nums = {1,-1,5,-2,3}; int k = 3;
    vector<int> nums = {-2,-1,2,1}; int k = 1;
    int ans = sol.maxSubArrayLen(nums, k);
    cout << ans << endl; 
    system("pause");
    return 0;
}
