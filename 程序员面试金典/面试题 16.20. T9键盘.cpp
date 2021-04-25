/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-19 16:12:10
 * @LastEditTime: 2021-04-19 16:20:55
 * @FilePath: \Leetcode\程序员面试金典\面试题 16.20. T9键盘.cpp
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
TIME:     44ms    BEAT: 16.33%    O(n) = 
MEMORY: 15.5MB    BEAT: 18.63%    O(n) = 
USED TIME: 10:59
LAST EDIT TIME: 2021年4月19日16:20:39
Description: 
*/

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        VS res;
        for (string word: words) {
            string cur_num = "";
            for (char c: word) cur_num += chartoNum(c);
            if (cur_num == num) res.PB(word);
        }
        return res;
    }

    string chartoNum(char& c) {
        if (c >= 'a' && c <= 'c') return "2";
        if (c >= 'd' && c <= 'f') return "3";
        if (c >= 'g' && c <= 'i') return "4";
        if (c >= 'j' && c <= 'l') return "5";
        if (c >= 'm' && c <= 'o') return "6";
        if (c >= 'p' && c <= 's') return "7";
        if (c >= 't' && c <= 'v') return "8";
        return "9";
    }
};