/*
 * @Description: 
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-12-03 18:42:59
 * @LastEditTime: 2020-12-03 18:55:59
 * @FilePath: \Leetcode\204.Count Primes.cpp
 */
/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        
        vector<int> list(n, 1);

        int ans = 0;
        for (int i = 2; i < n; i ++){
            if (list[i]){
                ans ++;
                long long j = i;
                while (j * i < n)
                {
                    list[j * i] = 0;
                    j ++ ;
                }
                
            }
        }
        return ans;
    }
};

int main(){
    Solution sol1;
    int A = sol1.countPrimes(100);
    cout << A << endl;
    system("pause");
    return 0;
}
// @lc code=end

