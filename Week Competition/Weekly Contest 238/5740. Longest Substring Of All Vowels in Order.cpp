/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-25 10:14:44
 * @LastEditTime: 2021-04-25 11:42:20
 * @FilePath: \Leetcode\Week Competition\Weekly Contest 238\t4.cpp
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


class Solution {
public:
    int longestBeautifulSubstring(string word) {
        unordered_map<char, int> q;
        q['a'] = 1;
        q['e'] = 2;
        q['i'] = 3;
        q['o'] = 4;
        q['u'] = 5;
        int res = 0;
        VI a_idx;
        REP(i, SZ(word)) if (word[i] == 'a' && ((i - 1 >= 0 && word[i - 1] != 'a') || i == 0)) a_idx.PB(i);
        REP(i, SZ(a_idx)) {
            int start_id = a_idx[i];
            int end_id = i == SZ(a_idx) - 1 ? SZ(word) - 1 : a_idx[i + 1] - 1;
            
            if (end_id - start_id + 1 < 5) continue;
            
            unordered_set<char> map;
            map.insert('a');
            char curCh = 'a';
            int id = start_id;

            FOR(k, start_id, end_id + 1) {
                if (word[k] < curCh) {
                    id = k - 1;
                    break;
                }
                else if (word[k] > curCh) {
                    map.insert(word[k]);
                    curCh = word[k];
                    id = k;
                }
                else {
                    id = k;
                }
            }
            if (SZ(map) == 5) {
                ckmax(res, id - start_id + 1);
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    // VI nums = {};
    // VVI nums = {};
    // auto ans = sol.longestBeautifulSubstring("aeiaaioaaaaeiiiiouuuooaauuaeiu");
    // auto ans = sol.longestBeautifulSubstring("aeeeiiiioooauuuaeiou");
    // auto ans = sol.longestBeautifulSubstring("aaaaaaaaaaaaaaaaaaaa");
    auto ans = sol.longestBeautifulSubstring("aaeeiiouuu");
    cout << ans << endl;
    // REP(i, SZ(ans)) cout << ans[i] << endl;
    // REP(i, SZ(ans)) REP(j, SZ(ans[0])) cout << ans[i][j] << endl;
    system("pause");
    return 0;
}