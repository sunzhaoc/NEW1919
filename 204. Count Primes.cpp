/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2020-12-03 18:42:59
 * @LastEditTime: 2021-05-24 22:42:47
 * @FilePath: \Leetcode\204. Count Primes.cpp
 */
/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

# define POW2(X) (1 << (X))
# define CKBIT(S,X) (((S) & POW2(X)) != 0)
const double pi = acos(-1.0);
const double eps = 1e-11;
const int MOD = 1e9 + 7;
template<class T> inline void ckmin(T &a,T b){ a = min(a, b); }
template<class T> inline void ckmax(T &a,T b){ a = max(a, b); }
template<class T> inline T sqr(T x){ return x * x; }
# define SZ(A) ((int)A.size())
# define LENGTH(A) ((int)A.length())
# define MP make_pair
# define PB push_back
# define PPB pop_back
# define PF push_front
# define PPF pop_front
# define LB lower_bound
# define UB upper_bound
# define RREP(i, a) for (int i = (a - 1); i >= 0; --i)
# define FOR(i, a, b) for(int i = (a); i < (b); ++i) 
# define REP(i, a) for(int i = 0; i < (a); ++i)
# define ALL(A) A.begin(), A.end()
# define RALL(A) A.rbegin(), A.rend()
# define complete_unique(a) a.erase(unique(begin(a),end(a)),end(a))
# define F first
# define S second
# define L left
# define R right
# define V vector 
template<class T> int CMP(T a[], const T b[], int n) { return memcmp(a, b, n * sizeof(T)); }
template<class T> void COPY(T a[], const T b[], int n) { memcpy(a, b, n * sizeof(T)); }
template<class T> void SET(T a[], int val, int n) { memset(a, val, n*sizeof(T)); }
using uint = unsigned int;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using VPII = vector<PII>;
using PLL = pair<LL, LL>;
using VPLL = vector<PLL>;
using VI = vector<int>;
using VVI = vector<VI>;
using VD = vector<double>;
using VDD = vector<VD>;
using VS = vector<string>;
using VVS = vector<VS>;


/*
RESULT: Accept
TIME:    208ms    BEAT: 26.91%    O(n) = 
MEMORY: 74.9MB    BEAT:  5.07%    O(n) = 
LAST EDIT TIME: 2021年5月24日22:41:45
Description: 线性筛。
*/

class Solution {
public:
    int countPrimes(int x) { 
        vector<int> prime(x);
        vector<int> st(x);
        int cnt = 0;
        for(int i = 2; i < x; i++) {
            if(!st[i]) prime[cnt++] = i;
            for(int j = 0; prime[j] <= (x - 1) / i; j++) {
                st[prime[j] * i] = true;
                if(i % prime[j] == 0) break;
            }
        }
        return cnt;
    }
};


/*
RESULT: Accept
TIME:    64ms    BEAT: 60.91%    O(n) = 
MEMORY: 7.1MB    BEAT: 56.18%    O(n) = 
USED TIME: 03:50
LAST EDIT TIME: 2021年5月24日18:25:14
Description: 埃氏筛。
*/

class Solution {
public:
    int countPrimes(int x) {
        int cnt = 0;
        vector<bool> isPrime(x);
        for (int i = 2; i < x; i ++) {
            if (!isPrime[i]) {
                cnt ++;
                for (int j = i + i; j < x; j += i) isPrime[j] = true;
            }
        }
        return cnt; 
    }
};



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

