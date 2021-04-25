/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2020-12-04 21:38:36
 * @LastEditTime: 2020-12-07 13:50:11
 * @FilePath: \Leetcode\剑指 Offer 62. 圆圈中最后剩下的数字.cpp
 */
#include <iostream>
using namespace std;

/*
RESULT: Accept
TIME:     4ms    BEAT: 99.88%    O(n) = n
MEMORY: 6.3MB    BEAT: 34.63%    O(n) = 1
Description: 约瑟夫环问题，需了解其基本知识。再使用递归公式推导。
https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/huan-ge-jiao-du-ju-li-jie-jue-yue-se-fu-huan-by-as/
*/

class Solution {
public:
    int lastRemaining(int n, int m) {
        int pos = 0;
        for (int i = 2; i <= n; i ++){
            pos = (pos + m) % i;
        }
        return pos;
    }
};


int main(){
    Solution sol;
    int ans = sol.lastRemaining(5, 3);
    cout << ans << endl;
    system("pause");
    return 0;
}