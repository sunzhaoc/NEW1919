/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-22 13:46:00
 * @LastEditTime: 2021-01-22 14:20:03
 * @FilePath: \Leetcode\989.Add to Array-Form of Integer.cpp
 */
/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:     12ms    BEAT: 100.00%    O(n) = max(n, logK)
MEMORY: 26.3MB    BEAT:  50.72%    O(n) = max(n, logK)
USED TIME: 25:10
LAST EDIT TIME: 2021年1月22日14:19:7
Description: 
*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int tmp = 0;
        int index = 0;

        reverse(A.begin(), A.end());
        A.resize(max(to_string(K).size(), A.size()) + 1);

        while (K != 0 || tmp != 0) {
            A[index] = A[index] + (K % 10) + tmp;
            if (A[index] >= 10) {
                tmp = 1;
                A[index] %= 10;
            }
            else tmp = 0;
            K /= 10;
            index ++;
        }
        if (A.back() == 0) {
            A.pop_back();
        }
        reverse(A.begin(), A.end());
        return A;
    }
};


int main() {
    Solution sol;
    vector<int> A = {9,9,9,9,9}; int K = 1;
    vector<int> ans = sol.addToArrayForm(A, K);
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl; 
    }
    system("pause");
    return 0;
}
// @lc code=end

