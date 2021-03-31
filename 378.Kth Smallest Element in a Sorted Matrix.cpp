/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-31 10:06:54
 * @LastEditTime: 2021-03-31 13:27:04
 * @FilePath: \Leetcode\378.Kth Smallest Element in a Sorted Matrix.cpp
 */
/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第K小的元素
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
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
LAST EDIT TIME: 
Description: 
*/

class Solution {
public:
    int row, col;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0], r = matrix.back().back();
        row = matrix.size(), col = matrix[0].size();
        while (l < r) {
            int mid = (r - l) / 2 + l;
            auto x = caculate(matrix, mid);
            if (x != -1 && x == k) return mid;
            else if (x >= k) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int caculate(vector<vector<int>>& matrix, int mid) {
        int i = row - 1, j = 0;
        int cnt = 0;
        bool flag = false;
        while (i >= 0 && j < col) {
            if (matrix[i][j] == mid) flag = true;
            if (matrix[i][j] <= mid) {
                cnt += i + 1;
                j ++;
            }
            else i --;
        }
        return flag ? cnt : -1;
    }
};


/*
RESULT: Accept
TIME:     36ms    BEAT: 63.33%    O(n) = 
MEMORY: 13.9MB    BEAT: 21.13%    O(n) = 
USED TIME: 10:59
LAST EDIT TIME: 最大堆。
Description: 二刷。前一次是python。
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> st;
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[0].size(); j ++) {
                if (st.size() < k) st.push(matrix[i][j]);
                else {
                    st.push(matrix[i][j]);
                    st.pop();
                }
            }
        }
        // for (int i = 0; i < k - 1; i ++) st.pop();
        return st.top();
    }
};

// @lc code=end

