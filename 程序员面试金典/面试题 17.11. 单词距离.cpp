/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-19 19:28:06
 * @LastEditTime: 2021-04-19 20:18:04
 * @FilePath: \Leetcode\程序员面试金典\面试题 17.11. 单词距离.cpp
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
    int findClosest(vector<string>& words, string word1, string word2) {
        
    }
};


/*
RESULT: Accept
TIME:    136ms    BEAT: 50.15%    O(n) = 
MEMORY: 58.1MB    BEAT: 34.53%    O(n) = 
LAST EDIT TIME: 2021年4月19日20:14:33
Description: 
*/

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int n = SZ(words);
        int id1 = -1, id2 = -1;
        int i = 0;
        int res = INT_MAX;
        while (id1 == -1 || id2 == -1) {
            if (words[i] == word1) id1 = i;
            else if (words[i] == word2) id2 = i;
            i ++;
        }
        res = abs(id1 - id2);

        while (i < SZ(words)) {
            if (id1 < id2) {
                i = id1 + 1;
                while (i < SZ(words) && (words[i] != word1 || i < id2)) {
                    if (words[i] == word1) {
                        id1 = i;
                        ckmin(res, abs(id1 - id2));
                    }
                    i ++;
                }
                id1 = i;
                if (i < SZ(words) && words[i] == word1) ckmin(res, abs(id1 - id2));
            }
            else {
                i = id2 + 1;
                while (i < SZ(words) && (words[i] != word2 || i < id1)) {
                    if (words[i] == word2) {
                        id2 = i;
                        ckmin(res, abs(id1 - id2));
                    }
                    i ++;
                }
                id2 = i;
                if (i < SZ(words) && words[i] == word2) ckmin(res, abs(id1 - id2));
            }
        }
        return res;
    }
};