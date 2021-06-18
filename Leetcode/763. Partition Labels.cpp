/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-22 21:44:16
 * @LastEditTime: 2021-04-22 22:30:55
 * @FilePath: \Leetcode\763. Partition Labels.cpp
 */
/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
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
TIME:     4ms    BEAT: 68.17%    O(n) = 
MEMORY: 6.6MB    BEAT: 21.57%    O(n) = 
USED TIME: 43:56
LAST EDIT TIME: 2021年4月22日22:30:34
Description: 真累。无语。
*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        V<PII> map(26, MP(-1, -1));
        REP(i, SZ(S)) {
            if (map[S[i] - 'a'] != MP(-1, -1)) map[S[i] - 'a'] = MP(map[S[i] - 'a'].F, i);
            else map[S[i] - 'a'] = MP(i, i);
        }

        sort(ALL(map), [] (const PII&x, const PII& y) {
            return x.S - x.F > y.S - y.F || (x.S - x.F == y.S - y.F && x.F > y.F);
        });
        
        VPII space;
        for (auto it: map) {
            int l = it.F;
            int r = it.S;
            if (l == -1) break;
            bool flag = true;
            for (auto& subspace: space) {
                if (l > subspace.F && l < subspace.S) {
                    ckmax(subspace.S, r);
                    flag = false;
                    break;
                }
                else if (r > subspace.F && r < subspace.S) {
                    ckmin(subspace.F, l);
                    flag = false;
                    break;
                }
            }
            if (flag) space.PB(MP(l, r));
        }

        sort(ALL(space), [] (const PII&x, const PII& y) {
            return x.S < y.S;
        });

        VI res;
        REP(i, SZ(space)) res.PB(space[i].S - space[i].F + 1);
        return res;
    }
};

int main() {
    Solution sol;
    auto ans = sol.partitionLabels("ababcbacadefegdehijhklij");
    // cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

