/*
 * @Description:
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-01 16:17:23
 * @LastEditTime: 2021-04-01 16:37:51
 * @FilePath: \Leetcode\1005.Maximize Sum Of Array After K Negations.cpp
 */
/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
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
TIME:     8ms    BEAT: 63.28%    O(n) = 
MEMORY: 8.9MB    BEAT: 24.50%    O(n) = 
USED TIME: 05:12
LAST EDIT TIME: 2021年4月1日16:37:30
Description: 二刷。python before。
*/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int a: A) q.push(a);
        for (int i = 0; i < K; i ++) {
            int tmp = q.top();
            q.pop();
            q.push(tmp * -1);
        }
        int sum = 0;
        while (q.size()) {
            sum += q.top();
            q.pop();
        }
        return sum;        
    }
};

// @lc code=end

