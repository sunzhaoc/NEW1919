/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-14 14:27:39
 * @LastEditTime: 2021-01-14 15:48:03
 * @FilePath: \Leetcode\1018.Binary Prefix Divisible By 5.cpp
 */
/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
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
TIME:     16ms    BEAT: 96.59%    O(n) = n
MEMORY: 13.2MB    BEAT: 98.86%    O(n) = n
LAST EDIT TIME: 2021年1月14日15:43:13
Description: 程序上改进了一下。
*/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;

        int tmp = 0;
        for (int &i: A) {
            tmp = ((tmp << 1) + i) % 5;
            res.push_back(!tmp);
        }

        return res;
    }
};


/*
RESULT: Accept
TIME:      8ms    BEAT: 100.00%    O(n) = n
MEMORY: 13.1MB    BEAT:  99.77%    O(n) = n
USED TIME: 06:51
LAST EDIT TIME: 2021年1月14日14:38:14
Description: 同余定理。
*/

// class Solution {
// public:
//     vector<bool> prefixesDivBy5(vector<int>& A) {
//         vector<bool> res;

//         int tmp = 0;
//         for (int i = 0; i < A.size(); i ++) {
//             tmp = (tmp * 2 + A[i]) % 5;
//             if (tmp == 0) res.push_back(true);
//             else res.push_back(false);
//         }

//         return res;
//     }
// };


int main() {
    Solution sol;
    // vector<int> A = {0,1,1};
    // vector<int> A = {1,1,1};
    vector<int> A = {0,1,1,1,1,1};
    // vector<int> A = {1,1,1,0,1};

    vector<bool> ans = sol.prefixesDivBy5(A);
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}
// @lc code=end

