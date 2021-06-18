/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-21 15:14:19
 * @LastEditTime: 2021-05-27 17:03:11
 * @FilePath: \Leetcode\372. 超级次方.cpp
 */
/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */

// @lc code=start

/*
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ████━████ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 * 
 */

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
TIME:     16ms    BEAT: 53.47%    O(n) = 
MEMORY: 11.3MB    BEAT: 60.93%    O(n) = 
LAST EDIT TIME: 2021年5月27日16:59:9
Description: 快速幂（递归）
*/

class Solution {
public:
    const int MOD = 1337;
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int k = b.back();
        b.pop_back();

        int part1 = quick_pow(a, k);
        int part2 = quick_pow(superPow(a, b), 10);

        return (part1 * part2) % MOD;
    }

    int quick_pow(int a, int k) {
        if (k == 0) return 1;
        long long res = quick_pow(a, k / 2);
        return k % 2 == 0 ? res * res % MOD : res * res % MOD * a % MOD;
    }
};


/*
RESULT: Accept
TIME:      8ms    BEAT: 95.24%    O(n) = 
MEMORY: 11.3MB    BEAT: 78.28%    O(n) = 
LAST EDIT TIME: 2021年5月27日16:52:31
Description: 快速幂（位运算）
*/

class Solution {
public:
    const int MOD = 1337;
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int k = b.back();
        b.pop_back();

        int part1 = quick_pow(a, k);
        int part2 = quick_pow(superPow(a, b), 10);

        return (part1 * part2) % MOD;
    }

    int quick_pow(int a, int k) {
        long long res = 1, base = a;
        while (k) {
            if (k & 1) res = res * base % MOD;
            base = base * base % MOD;
            k >>= 1;
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     28ms    BEAT: 50.17%    O(n) = 
MEMORY: 11.9MB    BEAT: 13.99%    O(n) = 
Description: 快速幂运算 + 递归。
*/

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last = b.back();
        b.pop_back();

        int part1 = myPow(a, last);
        int part2 = myPow(superPow(a, b), 10);

        return (part1 * part2) % 1337;
    }

private:
    int myPow(int a, int k) {
        a %= 1337;
        int res = 1;
        for (int _ = 0; _ < k; _ ++) {
            res *= a;
            res %= 1337;
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> b = {3};
    int ans = sol.superPow(2, b);
    cout << ans << endl;
    return 0;
}

// @lc code=end

