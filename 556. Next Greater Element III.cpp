/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-05 14:34:03
 * @LastEditTime: 2021-03-05 15:39:56
 * @FilePath: \Leetcode\556.Next Greater Element III.cpp
 */
/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
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
TIME:     0ms    BEAT: 100.00%    O(n) = n
MEMORY: 5.7MB    BEAT:  98.10%    O(n) = n
USED TIME: 25:52
LAST EDIT TIME: 2021年3月5日15:36:47
Description: 
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        if (n < 10) return -1;
        stack<int> st;
        vector<int> nums;
        while (n != 0) {
            int tmp = n % 10;
            if (!st.empty() && tmp < st.top()) {
                int num;
                while (!st.empty() && tmp < st.top()) {
                    num = st.top();
                    st.pop();
                    nums.emplace_back(num);
                }
                n = (n / 10) * 10 + num;
                nums[nums.size() - 1] = tmp;
                while (!st.empty()) {
                    nums.emplace_back(st.top());
                    st.pop();
                }
                sort(nums.begin(), nums.end());
                long N = n;
                for (int i = 0; i < nums.size(); i ++) {
                    N = N * 10 + nums[i];
                }
                return N > INT_MAX ? -1 : N;
            }
            st.push(tmp);
            n /= 10;
        }
        return -1;
    }
};


int main() {
    Solution sol;
    int ans = sol.nextGreaterElement(158476531);
    cout << ans << endl;
    system("pause");
    return 0;
}
// @lc code=end

