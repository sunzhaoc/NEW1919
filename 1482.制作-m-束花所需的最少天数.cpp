/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-22 14:44:48
 * @LastEditTime: 2021-05-22 14:55:24
 * @FilePath: \Leetcode\1482.制作-m-束花所需的最少天数.cpp
 */
/*
 * @lc app=leetcode.cn id=1482 lang=cpp
 *
 * [1482] 制作 m 束花所需的最少天数
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
TIME:    148ms    BEAT: 94.85%    O(n) = 
MEMORY: 61.8MB    BEAT: 54.42%    O(n) = 
LAST EDIT TIME: 2021年5月22日14:54:52
Description: 二分。
*/

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = SZ(bloomDay);
        if (m * k > n) return -1;

        int l = 1, r = *max_element(ALL(bloomDay));
        while (l < r) {
            int mid = (r - l) / 2 + l;
            int numMake = 0, numBloom = 0;
            for (int& x: bloomDay) {
                numBloom = x <= mid ? numBloom + 1 : 0;
                if (numBloom == k) {
                    numMake ++;
                    numBloom = 0;
                }
            }
            if (numMake >= m) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

// @lc code=end

