/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-30 12:33:41
 * @LastEditTime: 2021-03-30 14:50:27
 * @FilePath: \Leetcode\1808.Maximize Number of Nice Divisors.cpp
 */


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
LAST EDIT TIME: 2021年03月30日13:37:45
Description: 
*/

class Solution {
public:
    int maxNiceDivisors(int n) {
        if (n <= 3) return n;
        long res = 1;
        if (n % 3 == 1) res = (res * 4) % 1000000007, n -= 4;
        else if (n % 3 == 2) res = res * 2 % 1000000007, n -= 2;
        
        long long tmp = 1;
        tmp = qucikMul(3, n / 3);
        return res * tmp % 1000000007;
    }


    double qucikMul(int x, int n) {
        if (n == 0) return 1;
        long long ans = qucikMul(x , n / 2);
        return n % 2 == 0 ? ans * ans % 1000000007 : ans * ans * x % 1000000007;
    }
};


int main() {
    Solution sol;
    // int ans = sol.maxNiceDivisors(545918790);
    int ans = sol.maxNiceDivisors(98);
    cout << ans << endl;
    system("pause");
    return 0;
}

