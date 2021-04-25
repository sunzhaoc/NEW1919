/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-22 21:26:32
 * @LastEditTime: 2021-04-22 21:34:10
 * @FilePath: \Leetcode\281. Zigzag Iterator.cpp
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
TIME:     8ms    BEAT: 66.67%    O(n) = 
MEMORY: 8.2MB    BEAT: 13.33%    O(n) = 
USED TIME: 06:33
LAST EDIT TIME: 
Description: 
*/

class ZigzagIterator {
public:
    VI nums;
    int idx = 0;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int id1 = 0, id2 = 0;
        while (id1 < SZ(v1) && id2 < SZ(v2)) {
            nums.PB(v1[id1 ++]);
            nums.PB(v2[id2 ++]);
        }
        if (id1 == SZ(v1)) {
            FOR(i, id2, SZ(v2)) nums.PB(v2[i]);
        }
        else if (id2 == SZ(v2)) {
            FOR(i, id1, SZ(v1)) nums.PB(v1[i]);
        }
    }

    int next() {
        return nums[idx ++];
    }

    bool hasNext() {
        return idx < SZ(nums);
    }
};


/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */