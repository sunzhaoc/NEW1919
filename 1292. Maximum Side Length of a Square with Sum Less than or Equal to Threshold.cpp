/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-01 16:50:49
 * @LastEditTime: 2021-04-01 18:43:08
 * @FilePath: \Leetcode\1292.Maximum Side Length of a Square with Sum Less than or Equal to Threshold.cpp
 */
/*
 * @lc app=leetcode.cn id=1292 lang=cpp
 *
 * [1292] 元素和小于等于阈值的正方形的最大边长
 */

// @lc code=start#include <iostream>
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
TIME:    124ms    BEAT: 73.68%    O(n) = 
MEMORY: 21.8MB    BEAT: 58.85%    O(n) = 
USED TIME: 挺久。
LAST EDIT TIME: 2021年4月1日18:42:11
Description: 二刷。python before。
二维前缀和 + 二分 + 变态边界处理。草。。。。
*/

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        vector<vector<int>> sum(mat.size() + 1, vector<int>(mat[0].size() + 1, 0));
        for (int i = 0; i < mat.size(); i ++) {
            for (int j = 0; j < mat[0].size(); j ++) {
                sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + mat[i][j];
            }
        }
        
        int res = 0;
        int l = 1, r = min(mat.size(), mat[0].size());
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            bool flag = false;
            for (int i = 1; i < mat.size() - (mid - 1) + 1; i ++) {
                for (int j = 1; j < mat[0].size() - (mid - 1) + 1; j ++) {
                    if (sum[i + mid - 1][j + mid - 1] + sum[i - 1][j - 1] - sum[i + mid - 1][j - 1] - sum[i - 1][j + mid - 1] <= threshold) {
                        flag = true;
                        res = mid;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) l = mid + 1;
            else r = mid - 1;
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> nums = {{1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2}};
    int ans = sol.maxSideLength(nums, 4);
    system("pause");
    return 0;
}


// @lc code=end

