/*
 * @Description: 
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-12-10 10:20:34
 * @LastEditTime: 2020-12-10 10:31:11
 * @FilePath: \Leetcode\860.柠檬水找零.cpp
 */
/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:     36ms    BEAT: 55.30%    O(n) = n
MEMORY: 16.3MB    BEAT:  8.20%    O(n) = 1
Description: 
*/

class Solution {
public:
    bool lemonadeChange(vector<int> bills) {
        if (bills[0] != 5)  return false;
        
        int five = 1, ten = 0;
        
        for (int i = 1; i < bills.size(); i ++) {
            if (bills[i] == 5) five ++;
            if (bills[i] == 10) {
                if (five == 0)  return false;
                else {
                    ten ++;
                    five --;
                }
            }
            if (bills[i] == 20) {
                if (ten >= 1 && five >= 1) {
                    ten --;
                    five --;
                }
                else if (ten == 0 and five >= 3) five -= 3;
                else return false;
            }
        }
        return true;
    }
};


int main() {
    Solution sol;
    bool A = sol.lemonadeChange({5, 5, 5, 10, 20});
    cout << A << endl;
    system("pause");
    return 0;
}
// @lc code=end

