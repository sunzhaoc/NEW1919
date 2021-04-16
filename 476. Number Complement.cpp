/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-08 20:11:44
 * @LastEditTime: 2021-03-08 20:31:43
 * @FilePath: \Leetcode\476.Number Complement.cpp
 */
/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 5.8MB    BEAT:  65.39%    O(n) = 
LAST EDIT TIME: 2021年3月8日20:24:41
Description: Y总
*/

class Solution {
public:
    int findComplement(int num) {
        int res = 0, t = 0;
        while (num) {
            res += !(num & 1) << t;
            num >>= 1;
            t ++;
        }
        return res;
    }
};


int main() {
    Solution sol;
    int ans = sol.findComplement(13);
    cout << ans << endl;
    system("pause");
    return 0;
}
// @lc code=end

