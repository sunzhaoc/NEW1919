/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-31 10:06:54
 * @LastEditTime: 2021-03-31 13:29:43
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
TIME:     28ms    BEAT: 88.03%    O(n) = 
MEMORY: 12.7MB    BEAT: 67.44%    O(n) = 
LAST EDIT TIME: 2021年3月31日13:28:34
Description: 二分查找。
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
            if (x.second && x.first == k) return mid; // 注意还需要判断mid这个数是否存在于matrix中。
            else if (x.first >= k) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    pair<int, bool> caculate(vector<vector<int>>& matrix, int mid) {
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
        return {cnt, flag};
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
        return st.top();
    }
};

// @lc code=end

