/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2020-11-29 22:48:24
 * @LastEditTime: 2020-11-29 23:03:37
 * @FilePath: \Leetcode\976.三角形的最大周长.cpp
 */
/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 */

// @lc code=start
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for (int i = (int)A.size() - 1; i >= 2; i --){

            if (A[i - 2] + A[i - 1] > A[i]){

                return A[i - 2] + A[i - 1] + A[i];
            }
        }
        return 0;
    }
};

// @lc code=end

