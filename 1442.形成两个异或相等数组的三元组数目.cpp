/*
 * @lc app=leetcode.cn id=1442 lang=cpp
 *
 * [1442] 形成两个异或相等数组的三元组数目
 */

// @lc code=start

/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-05 20:05:57
 * @LastEditTime: 2021-05-18 10:31:55
 * @FilePath: \Leetcode\1442.形成两个异或相等数组的三元组数目.cpp
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
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
USED TIME: 
LAST EDIT TIME: 
Description: 
*/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = SZ(arr);
        unordered_map<int, int> cnt, total;
        int ans = 0, s = 0;
        REP(k, n) {
            int val = arr[k];
            if (cnt.count(s ^ val)) ans += cnt[s ^ val] * k - total[s ^ val];
            cnt[s] ++;
            total[s] += k;
            s ^= val;
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 73.95%    O(n) = n^2
MEMORY: 7.3MB    BEAT: 50.23%    O(n) = n
LAST EDIT TIME: 2021年5月18日10:5:43
Description: 
*/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt = 0;
        int n = SZ(arr);
        VI pre_arr;
        pre_arr.PB(arr[0]);
        FOR(i, 1, n) pre_arr.PB(pre_arr[i - 1] ^ arr[i]);
        REP(i, n) {
            FOR(k, i + 1, n) {
                if (i != 0 && pre_arr[i - 1] == pre_arr[k]) cnt += k - i;
                else if (i == 0 && pre_arr[k] == 0) cnt += k - i;
            }
        }
        return cnt;
    }
};


/*
RESULT: Accept
TIME:   176ms    BEAT: 13.02%    O(n) = n^3
MEMORY: 7.2MB    BEAT: 74.88%    O(n) = n
USED TIME: 07:10
LAST EDIT TIME: 2021年5月18日9:41:26
Description: 前缀异或。
*/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt = 0;
        int n = SZ(arr);
        VI pre_arr;
        pre_arr.PB(arr[0]);
        FOR(i, 1, n) pre_arr.PB(pre_arr[i - 1] ^ arr[i]);
        REP(i, n) {
            FOR(j, i + 1, n) {
                int a = i == 0 ? pre_arr[j - 1] : pre_arr[j - 1] ^ pre_arr[i - 1];
                FOR(k, j, n) {
                    int b = pre_arr[k] ^ pre_arr[j - 1];
                    if (a == b) cnt ++;
                }
            }
        }
        return cnt;
    }
};

// @lc code=end

