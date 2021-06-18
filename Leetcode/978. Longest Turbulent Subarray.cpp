/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-02-08 20:54:48
 * @LastEditTime: 2021-02-08 21:15:50
 * @FilePath: \Leetcode\978.Longest Turbulent Subarray.cpp
 */
/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
using namespace std;


/*
RESULT: Accept
TIME:     84ms    BEAT: 91.65%    O(n) = n
MEMORY: 39.7MB    BEAT: 74.80%    O(n) = n
LAST EDIT TIME: 2021年2月8日21:15:4
Description: 用的数组定义DP，所以内存会少一点。
*/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int up_arr[40000] = {1};
        int down_arr[40000] = {1};
        int ans = 1;

        for (int i = 1; i < arr.size(); i ++) {
            if (arr[i] > arr[i - 1]) {
                up_arr[i] = down_arr[i - 1] + 1;
                down_arr[i] = 1;
            }
            else if (arr[i] < arr[i - 1]) {
                down_arr[i] = up_arr[i - 1] + 1;
                up_arr[i] = 1;
            }
            else {
                down_arr[i] = 1;
                up_arr[i] = 1;
            }
            ans = max(ans, max(up_arr[i], down_arr[i]));
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:     84ms    BEAT: 91.65%    O(n) = n
MEMORY: 42.7MB    BEAT: 25.89%    O(n) = n
LAST EDIT TIME: 2021年2月8日21:3:40
Description: DP
*/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> up_arr(arr.size(), 1), down_arr(arr.size(), 1);
        int ans = 1;

        for (int i = 1; i < arr.size(); i ++) {
            if (arr[i] > arr[i - 1]) {
                up_arr[i] = down_arr[i - 1] + 1;
            }
            else if (arr[i] < arr[i - 1]) {
                down_arr[i] = up_arr[i - 1] + 1;
            }
            ans = max(ans, max(up_arr[i], down_arr[i]));
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {9,4,2,10,7,8,8,1,9};
    int ans = sol.maxTurbulenceSize(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}
// @lc code=end

