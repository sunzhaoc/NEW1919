/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-05 14:48:06
 * @LastEditTime: 2021-04-06 14:20:08
 * @FilePath: \Leetcode\weekcom\LCCUP2021 春季赛 个人\LCP 28. 采购方案.cpp
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

typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;

const int N = 1e9+7;


/*
RESULT: Accept
TIME:    144ms    BEAT: 100.00%    O(n) = nlogn ?
MEMORY: 58.8MB    BEAT: 100.00%    O(n) = logn ?
LAST EDIT TIME: 2021年4月6日13:55:51
Description: 根据楼教主的代码写成自己的。双指针。
*/

class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int n = nums.size();
        int j = n - 1;
        for (int i = 0; i < n; i ++) {
            for (; j > i && nums[i] + nums[j] > target; j --);
            if (j == i) break;
            cnt = (cnt + j - i) % N;
        }
        return cnt % N;
    }
};


/*
RESULT: Accept
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
LAST EDIT TIME: 2021年4月6日13:48:19
Description: 楼教主's code.
*/

class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int n = nums.size();

        for (int j = n - 1, i = 0; i < n; i ++) {
            for (; j > i && nums[i] + nums[j] > target; -- j);
            if (j <= i) break;
            cnt = (cnt + j - i) % N;
        }
        return cnt % N;
    }
};