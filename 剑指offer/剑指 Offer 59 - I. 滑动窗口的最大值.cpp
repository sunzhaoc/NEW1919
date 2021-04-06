/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-07 10:30:58
 * @LastEditTime: 2021-01-07 13:12:58
 * @FilePath: \Leetcode\剑指 Offer 59 - I. 滑动窗口的最大值.cpp
 */


#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;


/*
RESULT: Accept
TIME:     56ms    BEAT: 32.33%    O(n) = 
MEMORY: 16.1MB    BEAT: 28.96%    O(n) = 
Description: 
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k) return {};
        int l = 1 - k, r = 0;

        deque<int> dq;
        vector<int> res;

        while (r < nums.size()) {
            if (l >= 1 && nums[l - 1] == dq[0]) dq.pop_front();

            while (!dq.empty() && dq[0] < nums[r]) dq.pop_front();
            while (!dq.empty() && dq[dq.size() - 1] < nums[r]) dq.pop_back();
            dq.push_back(nums[r]);

            if (l >= 0) res.push_back(dq[0]);
            l ++;
            r ++;
        }

        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1,3,1,2,0,5};
    vector<int>ans = sol.maxSlidingWindow(nums, 3);
    // cout << ans << endl;
    system("pause");
    return 0;
}

