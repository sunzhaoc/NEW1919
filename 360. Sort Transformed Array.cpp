/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-08 15:23:04
 * @LastEditTime: 2021-03-08 15:31:22
 * @FilePath: \Leetcode\360.Sort Transformed Array.cpp
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
TIME:   0ms    BEAT: 100.00%    O(n) = nlogn
MEMORY: 9MB    BEAT:  84.34%    O(n) = logn
USED TIME: 01:26
LAST EDIT TIME: 2021年3月8日15:26:3
Description: 
*/

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        for (int i = 0; i < nums.size(); i ++) {
            nums[i] = a * nums[i] * nums[i] + b * nums[i] + c;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};
