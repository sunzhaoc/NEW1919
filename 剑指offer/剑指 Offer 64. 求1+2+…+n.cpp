/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2020-12-04 17:14:13
 * @LastEditTime: 2020-12-04 21:35:41
 * @FilePath: \Leetcode\剑指 Offer 64. 求1+2+…+n.cpp
 */
#include <iostream>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = n
MEMORY: 6.5MB    BEAT:  10.61%    O(n) = n
Description: 官解，递归，利用位运算符 && 的短路性质。
*/

class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};


int main(){
    Solution sol;
    int ans = sol.sumNums(5);
    cout << ans << endl;
    system("pause");
    return 0;
}