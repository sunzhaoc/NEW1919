/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-18 18:32:12
 * @LastEditTime: 2021-03-18 19:57:19
 * @FilePath: \Leetcode\350.Intersection of Two Arrays II.cpp
 */
/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
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
TIME:     12ms    BEAT: 36.92%    O(n) = 
MEMORY: 10.4MB    BEAT: 34,46%    O(n) = 
USED TIME: 01:56
LAST EDIT TIME: 2021年3月18日19:56:57
Description: 哈希。
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for (int num: nums1) map[num] ++;
    
        vector<int> res;
        for (int num: nums2) {
            if (map[num] > 0) {
                res.emplace_back(num);
                map[num] --;
            }
        }

        return res;
    }
};

// @lc code=end

