/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-09 15:13:48
 * @LastEditTime: 2021-04-09 15:26:19
 * @FilePath: \Leetcode\1286.Iterator for Combination.cpp
 */
/*
 * @lc app=leetcode.cn id=1286 lang=cpp
 *
 * [1286] 字母组合迭代器
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
TIME:     12ms    BEAT: 78.28%    O(n) = 
MEMORY: 12.5MB    BEAT: 35.35%    O(n) = 
USED TIME: 09:22
LAST EDIT TIME: 2021年4月9日15:23:43
Description: 
有个疑问。 a, b, c  n = 2 时的字典序。我本来认为的是 ab ac ba bc ca cb 而题目的意思是 ab ac bc.所以下面有一行被注释了。
*/

class CombinationIterator {
public:
    VS map;
    int id = -1;

    CombinationIterator(string characters, int combinationLength) {
        sort(ALL(characters));
        string tmp = "";
        backTrack(tmp, combinationLength, characters);
    }
    
    void backTrack(string& cur, int n, string& unused) {
        if (SZ(cur) == n) {
            map.PB(cur);
            return;
        }
        FOR (i, 0, SZ(unused)) {
            cur += unused[i];
            // string next_unused = unused.substr(0, i) + unused.substr(i + 1);
            string next_unused = unused.substr(i + 1);
            backTrack(cur, n, next_unused);
            cur = cur.substr(0, SZ(cur) - 1);
        }
    }

    string next() {
        return map[++ id];
    }
    
    bool hasNext() {
        int tmp = id + 1;
        if (tmp >= map.size()) return false;
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

