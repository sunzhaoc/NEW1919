/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-16 13:20:27
 * @LastEditTime: 2021-04-16 13:56:33
 * @FilePath: \Leetcode\1673. Find the Most Competitive Subsequence.cpp
 */
/*
 * @lc app=leetcode.cn id=1673 lang=cpp
 *
 * [1673] 找出最具竞争力的子序列
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
# define MP(A, B) make_pair(A, B)
# define PB(X) push_back(X)
# define FOR(i, a, b) for(int i = (a); i < (b); ++i)
# define REP(i, a) for(int i = 0; i < (a); ++i)
# define ALL(A) A.begin(), A.end()
# define F first
# define S second
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
RESULT: Time Out
TIME:     376ms    BEAT: 11.90%    O(n) = 
MEMORY: 118.4MB    BEAT:  8.01%    O(n) = 
USED TIME: 忘了。
LAST EDIT TIME: 2021年4月16日13:56:25
Description: 最小堆。
*/

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        struct cmp
        {
            bool operator() (const PII& x, const PII& y) {
                if (x.second == y.second) return x.first > y.first;
                return x.second > y.second;
            }
        };
        
        priority_queue<PII, VPII, cmp> minHeap;    // id, value
        
        REP(i, SZ(nums) - k + 1) {
            minHeap.push(MP(i, nums[i]));
        }

        VI res;
        int idx = SZ(nums) - k + 1;
        REP(i, k) {
            int id = minHeap.top().F;
            int value = minHeap.top().S;
            
            minHeap.pop();
            res.PB(value);

            while (minHeap.size() && minHeap.top().F < id) minHeap.pop();
            if (idx < SZ(nums)) minHeap.push(MP(idx, nums[idx]));
            idx ++;
        }
        return res;
    }
};


/*
RESULT: Time Out
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
USED TIME: 
LAST EDIT TIME: 
Description: 
*/

class Solution {
public:
    VI cur;
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        dfs(nums, cur, 0, k);
        return cur;
    }

    void dfs(VI& nums, VI& cur, int id, int k) {
        if (k == 0) return;
        int minNum = INT_MAX;
        int minId = -1;
        FOR(i, id, SZ(nums) - k + 1) {
            if (nums[i] < minNum) {
                minNum = nums[i];
                minId = i;
            }
        }
        cur.PB(minNum);
        dfs(nums, cur, minId + 1, k - 1);
    }
};

// @lc code=end

