/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-30 12:33:41
 * @LastEditTime: 2021-03-30 16:11:21
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 5.9MB    BEAT:  27.21%    O(n) = 
LAST EDIT TIME: 2021年3月30日16:10:56
Description: y总。
*/

typedef long long LL;
const int MOD = 1e9 + 7;

class Solution {
public:
    int qmi(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = (LL)res * a % MOD;
            a = (LL)a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int maxNiceDivisors(int m) {
        if (m <= 3) return m;
        if (m % 3 == 0) return qmi(3, m / 3);
        if (m % 3 == 1) return (LL)qmi(3, (m - 4) / 3) * 4 % MOD;
        return (LL)qmi(3, (m - 2) / 3) * 2 % MOD;
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100%    O(n) = 
MEMORY: 5.9MB    BEAT:   8%    O(n) = 
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

