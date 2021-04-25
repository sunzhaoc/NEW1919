/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2020-12-03 22:53:19
 * @LastEditTime: 2020-12-03 23:05:34
 * @FilePath: \Leetcode\剑指 Offer 17. 打印从1到最大的n位数.cpp
 */

#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

/*
RESULT: Accept
TIME: 20ms BEAT: 27%
MEMORY: 11.8MB BEAT: 7%
Description: 暴力解法
*/
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        for(int i = 1; i < pow(10, n); i ++)
            res.push_back(i);
        return res;
    }
};


int main(){
    Solution sol;
    vector<int> ans = sol.printNumbers(3);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}