/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-02 09:25:19
 * @LastEditTime: 2021-04-02 09:40:27
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
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
USED TIME: 
LAST EDIT TIME: 
Description: 
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
                
            }
            else {

            }
        }
    }
};