/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-17 21:09:32
 * @LastEditTime: 2021-03-18 14:43:40
 * @FilePath: \Leetcode\84.柱状图中最大的矩形.cpp
 */
/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
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
TIME:    140ms    BEAT: 48.27%    O(n) = 
MEMORY: 61.8MB    BEAT: 50.42%    O(n) = 
LAST EDIT TIME: 2021年3月18日14:41:22
Description: 参考Y总的代码。有点难想。
https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/bao-li-jie-fa-zhan-by-liweiwei1419/
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), res = 0;
        heights.push_back(-1);

        stack<int> st;
        for (int i = 0; i <= n; i ++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int cur = st.top();
                st.pop();
                if (st.empty()) {
                    res = max(res, heights[cur] * i);
                }
                else {
                    res = max(res, heights[cur] * (i - st.top() - 1));
                }
            }
            st.push(i);
        }
        return res;
    }
};


/*
RESULT: Time Out
LAST EDIT TIME: 2021年3月18日13:51:50
Description: 就知道。试试。也许能过呢。
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = INT_MIN;
        for (int i = 0; i < heights.size(); i ++) {
            int j = i;
            while (j < heights.size() - 1 && heights[j + 1] >= heights[i]) j ++;
            int k = i;
            while (k > 0 && heights[k - 1] >= heights[i]) k --;
            res = max(res, (j - k + 1) * heights[i]);
        }
        return res;
    }
};

// @lc code=end

