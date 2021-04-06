/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-06 19:07:19
 * @LastEditTime: 2021-01-06 19:38:10
 * @FilePath: \Leetcode\剑指 Offer 57 - II. 和为s的连续正数序列.cpp
 */
#include <iostream>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.8MB    BEAT:  79.34%    O(n) = 
USED TIME: 15:01
Description: 与下面的方法相同，只是用了等差数列的数学知识。
*/

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int l = 1;
        int r = 2;
        vector<vector<int>> res;
        vector<int> path;
        while (l < r) {
            int sum = (l + r) * (r - l + 1) / 2;
            if (sum == target) {
                path.clear();
                for (int i = l; i <= r; i ++) {
                    path.emplace_back(i);
                }
                res.emplace_back(path);
                l ++;
            }
            else if (sum < target) r ++;
            else l ++;
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:    616ms    BEAT: 5.09%    O(n) = 
MEMORY: 96.4MB    BEAT: 5.02%    O(n) = 
USED TIME: 10:25
Description: 
*/

// class Solution {
// public:
//     vector<vector<int>> findContinuousSequence(int target) {
//         vector<vector<int>> res;

//         int begin = 1;
//         int end = target / 2 + 1;
//         while (begin < end) {
//             int sum = 0;
//             vector<int> path;
//             for (int i = begin; i <= end; i ++) {
//                 sum += i;
//                 path.push_back(i);
//                 if (sum == target) {
//                     res.push_back(path);
//                     break;
//                 } 
//                 if (sum > target)
//                 {
//                     path.clear();
//                     break;
//                 }
                
//             }
//             begin ++;
//         }
//         return res;
//     }
// };


int main() {
    Solution sol;
    vector<vector<int>> ans = sol.findContinuousSequence(9);
    system("pause");
    return 0;
}