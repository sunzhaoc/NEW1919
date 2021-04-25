/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-25 16:52:36
 * @LastEditTime: 2021-04-25 17:14:56
 * @FilePath: \Leetcode\443. String Compression.cpp
 */
/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
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
TIME:     4ms    BEAT: 90.67%    O(n) = 
MEMORY: 8.6MB    BEAT: 45.33%    O(n) = 
LAST EDIT TIME: 这个比我的简洁多了。
Description: 
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = SZ(chars), index = 0;
        int i = 0;
        while (i < n) {
            if (i + 1 < n && chars[i] == chars[i + 1]) {
                int j = i + 1;
                while (j < n && chars[j] == chars[i]) j ++;
                string len = to_string(j - i);
                chars[index ++] = chars[i];
                for (auto& ch: len) chars[index ++] = ch;
                i = j;
            }
            else {
                chars[index ++] = chars[i ++];
            }
        }
        return index;
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 90.67%    O(n) = 
MEMORY: 8.6MB    BEAT: 38.05%    O(n) = 
USED TIME: 15:37
LAST EDIT TIME: 2021年4月25日17:8:58
Description: 
*/

class Solution {
public:
    int idx = 0;
    int res = 0;
    int compress(vector<char>& chars) {
        int l = 0, r = 0;
        while (r < SZ(chars)) {
            while (r < SZ(chars) && chars[r] == chars[l]) r ++;
            int num = r - l;
            moveChar(chars[l], num, chars);
            l = r;
        }
        return res;
    }

    void moveChar(char& a, int step, V<char>& chars) {
        if (step == 1) {
            chars[idx ++] = a;
            res += 1;
        }
        else {
            chars[idx ++] = a;
            if (step == 1000) {
                chars[idx ++] = '1';
                chars[idx ++] = '0';
                chars[idx ++] = '0';
                chars[idx ++] = '0';
                res += 5;
            }
            else if (step < 1000 && step >= 100) {
                chars[idx ++] = step / 100 + '0';
                step %= 100;
                chars[idx ++] = step / 10 + '0';
                step %= 10;
                chars[idx ++] = step + '0';
                res += 4;
            }
            else if (step < 100 && step >= 10) {
                chars[idx ++] = step / 10 + '0';
                step %= 10;
                chars[idx ++] = step + '0';
                res += 3;
            }
            else if (step > 1 && step < 10) {
                chars[idx ++] = step + '0';
                res += 2;
            }
        }
    }
};
// @lc code=end

