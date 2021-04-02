/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-02 09:25:19
 * @LastEditTime: 2021-04-02 09:47:57
 * @FilePath: \Leetcode\面试题 17.21. 直方图的水量.cpp
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
TIME:      8ms    BEAT: 61.71%    O(n) = 
MEMORY: 13.5MB    BEAT: 72.65%    O(n) = 
LAST EDIT TIME: 2021年4月2日9:47:28
Description: 同42题。也算是二刷了吧。
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2) return 0;
        int l = 0, r = height.size() - 1;
        int res = 0;
        
        int lmax = 0, rmax = 0;
        
        while (l < r) {
            if (height[l] < height[r]) {
                height[l] > lmax ? (lmax = height[l]) : res += lmax - height[l];
                l ++;
            }
            else {
                height[r] > rmax ? (rmax = height[r]) : res += rmax - height[r];
                r --;
            }
        }
        return res;
    }
};