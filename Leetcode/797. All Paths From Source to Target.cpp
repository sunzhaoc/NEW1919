/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-08 19:49:55
 * @LastEditTime: 2021-04-08 20:01:32
 * @FilePath: \Leetcode\797.All Paths From Source to Target.cpp
 */
/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
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
using VS = vector<string>;
using VVS = vector<VS>;

/*
RESULT: Accept
TIME:      8ms    BEAT: 98.89%    O(n) = 
MEMORY: 11.8MB    BEAT: 48.17%    O(n) = 
USED TIME: 09:07
LAST EDIT TIME: 2021年4月8日20:1:10
Description: 我都没想到这就能过了。
*/

class Solution {
public:
    VVI ans;
    int N;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        N = graph.size() - 1;
        VI init = {0};
        backTrack(init, graph);
        return ans;
    }
    
    void backTrack(VI& cur, VVI& graph) {
        if (cur.back() == N) {
            ans.PB(cur);
            return;
        }
        int id = cur.back();
        REP(i, SZ(graph[id])) {
            cur.PB(graph[id][i]);
            backTrack(cur, graph);
            cur.pop_back();
        }
    }
};
// @lc code=end

