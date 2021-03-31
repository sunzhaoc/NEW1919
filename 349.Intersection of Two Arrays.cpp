/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-31 09:47:04
 * @LastEditTime: 2021-03-31 14:25:44
 * @FilePath: \Leetcode\349.Intersection of Two Arrays.cpp
 */
/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
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
TIME:     4ms    BEAT: 95.31%    O(n) = 
MEMORY: 9.8MB    BEAT: 93.49%    O(n) = 
LAST EDIT TIME: 2021年3月31日9:55:40
Description: 排序 + 双指针。
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len1 = nums1.size(), len2 = nums2.size();
        int id1 = 0, id2 = 0;
        vector<int> res;
        while (id1 < len1 && id2 < len2) {
            if (nums1[id1] == nums2[id2]) {
                if (!res.size() || nums1[id1] != res.back()) res.push_back(nums1[id1]);
                id1 ++;
                id2 ++;
            }
            else if (nums1[id1] < nums2[id2]) id1 ++;
            else id2 ++;
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:    32ms    BEAT:  6.88%    O(n) = 
MEMORY: 9.9MB    BEAT: 85.57%    O(n) = 
USED TIME: 02:38 
LAST EDIT TIME: 2021年3月31日9:50:40
Description: 二刷。之前是python。暴力。
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> tmp;
        for (int i = 0; i < nums1.size(); i ++) {
            for (int j = 0; j < nums2.size(); j ++) {
                if (nums1[i] == nums2[j]) tmp.insert(nums1[i]);
            }
        }
        for (auto x: tmp) res.push_back(x);
        return res;
    }
};
// @lc code=end

