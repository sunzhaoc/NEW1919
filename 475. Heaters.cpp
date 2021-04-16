/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-17 21:09:47
 * @LastEditTime: 2021-03-18 15:35:35
 * @FilePath: \Leetcode\475.Heaters.cpp
 */
/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
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
#include <stack>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:     48ms    BEAT: 98.01%    O(n) = 
MEMORY: 24.8MB    BEAT: 47.35%    O(n) = 
LAST EDIT TIME: 2021年3月18日15:35:39
Description: 二分变态题。

*/

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        heaters.push_back(INT_MIN);
        heaters.push_back(INT_MAX);
        sort(heaters.begin(), heaters.end());

        int res = 0;
        for (int house: houses) {
            int l = 0, r = heaters.size() - 1;
            // 二分离房屋最近的右边的暖气。
            while (l < r) {
                int mid = (r - l) / 2 + l;
                if (heaters[mid] >= house) r = mid;
                else l = mid + 1; 
            }
            res = max(res, (int)min(heaters[r] - 0ll - house, house - 0ll - heaters[r - 1]));
        }
        return res; 
    }
};

// @lc code=end

