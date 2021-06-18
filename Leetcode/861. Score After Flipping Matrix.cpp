/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-01 15:06:38
 * @LastEditTime: 2021-04-01 15:17:53
 * @FilePath: \Leetcode\861.Score After Flipping Matrix.cpp
 */
/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
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
MEMORY: 7.6MB    BEAT:  98.23%    O(n) = 
USED TIME: 09:51
LAST EDIT TIME: 2021年4月1日15:17:18
Description: 二刷。前一次python。Easy。
*/

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int row = A.size(), col = A[0].size();
        for (int i = 0; i< row; i ++) {
            if (A[i][0] == 0) {
                for (int j = 0; j < col; j ++) {
                    A[i][j] = A[i][j] == 0 ? 1 : 0;
                }
            }
        }
        
        int res = 0;
        for (int j = 0; j < col; j ++) {
            int cnt = 0;
            for (int i = 0; i < row; i ++) {
                if (A[i][j] == 1) cnt ++;    
            }
            cnt = cnt > row / 2 ? cnt : row - cnt;
            res += cnt * (1 << (col - j - 1));
        }
        return res;
    }
};

// @lc code=end

