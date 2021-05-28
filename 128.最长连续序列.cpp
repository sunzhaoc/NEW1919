/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-28 15:28:28
 * @LastEditTime: 2021-05-28 15:53:19
 * @FilePath: \Leetcode\128.最长连续序列.cpp
 */
/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
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
TIME:     68ms    BEAT: 19.52%    O(n) = 
MEMORY: 30.2MB    BEAT:  5.01%    O(n) = 
LAST EDIT TIME: 2021年5月28日15:53:5
Description: 
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m;
        for (const int& num: nums) m.insert(num);
        int res = 0;
        for (const int& num: m) {
            if (!m.count(num - 1)) { // No number smaller than this number
                int curNum = num;
                int curLen = 1;
                while (m.count(curNum + 1)) {
                    curNum ++;
                    curLen ++;
                }
                ckmax(res, curLen);
            }
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     80ms    BEAT: 18.67%    O(n) = 
MEMORY: 30.3MB    BEAT:  5.01%    O(n) = 
LAST EDIT TIME: 2021年5月28日15:44:43
Description: 
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (SZ(nums) == 0) return 0;
        sort(ALL(nums));
        int idx = 0;
        int cnt = 1;
        while (idx < SZ(nums)) {
            unordered_set<int> m;
            m.insert(nums[idx]);
            while (idx + 1< SZ(nums) && nums[idx + 1] <= nums[idx] + 1) {
                m.insert(nums[idx + 1]);
                idx ++;
            }
            ckmax(cnt, SZ(m));
            idx ++;
        }
        return cnt;
    }
};


int main() {
    Solution sol;
    VI nums = {1,2,0,1};
    auto ans = sol.longestConsecutive(nums);
    cout << ans << endl;
    system("pause");
    return -1;
}
// @lc code=end

