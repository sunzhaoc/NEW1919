/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-19 21:13:26
 * @LastEditTime: 2021-04-19 21:18:47
 * @FilePath: \Leetcode\程序员面试金典\面试题 10.02. 变位词组.cpp
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
TIME:     36ms    BEAT: 88.60%    O(n) = 
MEMORY: 17.7MB    BEAT: 70.21%    O(n) = 
USED TIME: 04:44
LAST EDIT TIME: 2021年4月19日21:18:31
Description: 
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        VVS res;
        unordered_map<string, VS> map;
        for (string s: strs) {
            string key = s;
            sort(ALL(key));
            map[key].PB(s);
        }
        for (auto it = map.begin(); it != map.end(); it ++) {
            res.PB(it->S);
        }
        return res;
    }
};