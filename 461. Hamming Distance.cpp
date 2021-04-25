/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-04 19:06:19
 * @LastEditTime: 2021-01-04 19:20:28
 * @FilePath: \Leetcode\461.Hamming Distance.cpp
 */
/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 1
MEMORY: 6.3MB    BEAT:   6.86%    O(n) = 1
USED TIME: 03:46
Description: 布赖恩·克尼根算法。
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int temp = x ^ y;
        while (temp) {
            ans ++;
            temp &= (temp - 1);
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 31.20%    O(n) = 
MEMORY: 6.2MB    BEAT: 35.06%    O(n) = 
USED TIME: 03:46
Description: 
*/

// class Solution {
// public:
//     int hammingDistance(int x, int y) {
//         int ans = 0;
//         int temp1, temp2;
        
//         while (x | y) {
//             temp1 = x % 2;
//             temp2 = y % 2;
//             ans += (temp1 ^ temp2);
//             x /= 2;
//             y /= 2;
//         }
//         return ans;
//     }
// };

int main() {
    Solution sol;
    int ans = sol.hammingDistance(1, 4);
    cout << ans << endl;
    system("pause");
    return 0;
}
// @lc code=end

