/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-17 10:13:43
 * @LastEditTime: 2021-01-18 11:18:02
 * @FilePath: \Leetcode\1726.Tuple with Same Product.cpp
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
TIME:    564ms    BEAT: 100.00%    O(n) = 
MEMORY: 79.4MB    BEAT: 100.00%    O(n) = 
USED TIME: 11:00
LAST EDIT TIME: 2021-1-18 11:16:41
Description: 比赛的时候写的。
*/

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int first = 0; first < nums.size(); first ++) {
            for (int second = first + 1; second < nums.size(); second ++) {
                map[nums[first] * nums[second]] ++;
            }
        }

        int ans = 0;
        auto it = map.begin();
        while (it != map.end()) {
            if (it->second != 1) {
            ans += (it->second * (it->second - 1));
            }
            it ++;
        }

        return ans * 4;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {2,3,4,6};
    // vector<int> nums = {1,2,4,5,10};
    // vector<int> nums = {2,3,5,7};
    // vector<int> nums = {2,3,4,6,8,12};
    int ans = sol.tupleSameProduct(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}
