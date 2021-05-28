/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
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
TIME:     40ms    BEAT: 95.65%    O(n) = 
MEMORY: 18.6MB    BEAT: 10.51%    O(n) = 
LAST EDIT TIME: 2021年5月28日9:34:13
Description: 
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int cnt = 0, n = SZ(nums);
        for (int i = 0; i < 30; i ++) {
            int tmp = 0;
            for (int val: nums) {
                tmp += (val >> i) & 1;
            }
            cnt += tmp * (n - tmp);
        }
        return cnt;
    }
};


/*
RESULT: Time Out
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
LAST EDIT TIME: 2021年5月28日9:28:23
Description: 暴力枚举，超时。
*/

class Solution {
public:
    int hammingDistance(int& x) {
        int cnt = 0;
        while (x) {
            cnt ++;
            x &= (x - 1);
        }
        return cnt;
    }

    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        REP(i, SZ(nums)) {
            FOR(j, i + 1, SZ(nums)) {
                int x = nums[i] ^ nums[j];
                res += hammingDistance(x);
            }
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     40ms    BEAT: 94.46%    O(n) = 
MEMORY: 17.6MB    BEAT: 53.10%    O(n) = 
USED TIME: 04:49
LAST EDIT TIME: 2021年3月9日21:11:39
Description: 用了数学知识。
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int n = nums.size();
        vector<int> st(32, 0);
        for (int num: nums) {
            int i = 0;
            while (num) {
                st[i] += num & 1;
                num >>= 1;
                i ++;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i ++) {
            res += st[i] * (n - st[i]);
        }
        return res;
    }
};


/*
RESULT: Time Out
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i ++) {
            for (int j = i + 1; j < nums.size(); j ++) {
                ans += calHamming(nums[i], nums[j]);
            }
        }
        return ans;
    }
    
    int calHamming(int x, int y) {
        int tmp = x ^ y;
        int ans = 0;
        while (tmp) {
            if (tmp & 1) ans ++;
            tmp >>= 1;
        }
        return ans;
    }
};

// @lc code=end

