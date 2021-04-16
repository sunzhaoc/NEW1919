/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-15 21:21:04
 * @LastEditTime: 2021-01-15 21:53:50
 * @FilePath: \Leetcode\974.Subarray Sums Divisible by K.cpp
 */
/*
 * @lc app=leetcode.cn id=974 lang=cpp
 *
 * [974] 和可被 K 整除的子数组
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
TIME:     64ms    BEAT: 99.43%    O(n) = n
MEMORY: 29.8MB    BEAT: 87.31%    O(n) = min(n, k)
LAST EDIT TIME: 2021年1月15日21:50:54
Description: 下面的方法简洁写法。前缀和 + 哈希表。
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> map;
        int sum = 0;
        map[0] = 1;
        int count = 0;
        for (int i = 0; i < A.size(); i ++) {
            sum = (sum + A[i]) % K >= 0 ? (sum + A[i]) % K : K - abs((sum + A[i]) % K);

            auto it = map.find(sum);
                        
            if (it == map.end()) {
                map[sum] ++;
            }
            else {
                count += it->second;
                map[sum] ++;
            }       
        }
        return count;
    }
};


/*
RESULT: Accept
TIME:     56ms    BEAT: 100.00%    O(n) = 
MEMORY: 29.5MB    BEAT:  88.46%    O(n) = 
USED TIME: 22:57
LAST EDIT TIME: 2021年1月15日21:47:33
Description: 前缀和 + 哈希表。
*/

// class Solution {
// public:
//     int subarraysDivByK(vector<int>& A, int K) {
//         unordered_map<int, int> map;
//         int sum = 0;
//         map[0] = 1;
//         int count = 0;
//         for (int i = 0; i < A.size(); i ++) {
//             sum = (sum + A[i]) % K;
//             if (sum >= 0) {
//                 auto it = map.find(sum);
                            
//                 if (it == map.end()) {
//                     map[sum] ++;
//                 }
//                 else {
//                     count += it->second;
//                     map[sum] ++;
//                 }
//             }
//             else{
//                 auto it = map.find(K - abs(sum));
//                 if (it == map.end()) {
//                     map[K - abs(sum)] ++;
//                 }
//                 else {
//                     count += it->second;
//                     map[K - abs(sum)] ++;
//                 }
//             }
//         }
//         return count;
//     }
// };


int main() {
    Solution sol;
    // vector<int> A = {4,5,0,-2,-3,1}; int K = 5;
    
    vector<int> A = {-1,2,9}; int K = 2;
    int ans = sol.subarraysDivByK(A, K);
    cout << ans << endl; 
    system("pause");
    return 0;
}
// @lc code=end

