/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-21 15:44:07
 * @LastEditTime: 2021-04-28 14:57:59
 * @FilePath: \Leetcode\633. Sum of Square Numbers.cpp
 */
/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 5.9MB    BEAT:  15.60%    O(n) = 
LAST EDIT TIME: 2021年4月28日14:57:47
Description: 
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        int edge = sqrt(c);
        long long a = 0, b = edge;
        while (a <= b) {
            if (a * a + b * b == c) return true;
            if (a * a + b * b > c) b --;
            else a --;
        }
        return false;
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.2MB    BEAT:  22.65%    O(n) = 
Description: 
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        long l = 0, r = sqrt(c);    // 该处的r如果不用sqrt()函数，其实是由二分法得到。
        while (l <= r) {
            if (l * l + r * r == c) return true;
            else if (l * l + r * r > c) r --;
            else l ++;
        }
        return false;
    }
};


/*
RESULT: WRONG
TIME:   ms    BEAT: %    O(n) = sqrt(n)
MEMORY: MB    BEAT: %    O(n) = 1
Description: 利用sqrt函数。能运行但提交报错。
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        double temp;
        for (int i = 0; i <= c; i ++) {
            temp = sqrt(c - i *i);
            if (temp == (int)temp) return true;
        }
        return false;
    }
};


int main() {
    Solution sol;
    bool ans = sol.judgeSquareSum(61);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

