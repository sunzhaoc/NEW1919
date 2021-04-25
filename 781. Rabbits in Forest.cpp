/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-04 13:12:08
 * @LastEditTime: 2021-04-04 13:19:04
 * @FilePath: \Leetcode\781.森林中的兔子.cpp
 */
/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
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
TIME:     8ms    BEAT: 40.24%    O(n) = 
MEMORY: 8.3MB    BEAT: 70.52%    O(n) = 
USED TIME: 05:37
LAST EDIT TIME: 2021年4月4日13:18:24
Description: 兔老师华为面试题。
*/

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if (answers.size() == 0) return 0;
        unordered_map<int, int> map;
        for (int num: answers) {
            map[num] ++;
        }
        int res = 0;
        for (auto it = map.begin(); it != map.end(); it ++) {
            res += (it->second + (it->first + 1) - 1) / (it->first + 1)  * (it->first + 1);
        }
        return res;
    }
};
// @lc code=end

