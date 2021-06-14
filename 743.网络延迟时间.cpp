/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2021-06-08 09:41:11
 * @LastEditTime: 2021-06-08 10:12:56
 * @FilePath: \Leetcode\743.网络延迟时间.cpp
 */
/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
/*
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ██姜██━██狗██ ┃+
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
TIME:    124ms    BEAT: 85.58%    O(n) = 
MEMORY: 36.4MB    BEAT: 74.20%    O(n) = 
LAST EDIT TIME: 2021年6月8日10:11:38
Description: Dijkstra算法
*/

class Solution {
public:
    VVI g;
    VI dist;
    V<bool> st;

    int dijkstra(int& n, int& k) {
        for (int i = 0; i < n; i ++) {
            int t = -1;
            for (int j = 1; j <= n; j ++) {
                if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
            }
            
            st[t] = true;

            for (int j = 1; j <= n; j ++) {
                ckmin(dist[j], dist[t] + g[t][j]);
            }
            int tmp = 0;
        }
        return *max_element(dist.begin() + 1, dist.end());
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        g.resize(n + 1, VI(n + 1, 0x3f3f3f3f));
        dist.resize(n + 1, 0x3f3f3f3f);
        st.resize(n + 1, false);
        dist[k] = 0;
        for (int i = 0; i < SZ(times); i ++) {
            ckmin(g[times[i][0]][times[i][1]], times[i][2]);
        }
        int res = dijkstra(n, k);
        if (res >= 0x3f3f3f3f) return -1;
        return res;
    }
};

// @lc code=end

