/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-09 20:11:35
 * @LastEditTime: 2021-03-09 20:53:15
 * @FilePath: \Leetcode\201.Bitwise AND of Numbers Range.cpp
 */
/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
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
TIME:    20ms    BEAT: 17.80%    O(n) = 
MEMORY: 5.9MB    BEAT: 48.94%    O(n) = 
LAST EDIT TIME: 2021年3月9日20:37:41
Description: 妙的很。
*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int tmp = 1 << 30;
        int ans = 0;
        while (tmp > 0 && (left & tmp) == (right & tmp)) {
            ans |= left & tmp;
            tmp >>= 1;
        }
        return ans;
    }
};

// @lc code=end

