/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-04 20:51:53
 * @LastEditTime: 2021-04-09 21:58:49
 * @FilePath: \Leetcode\demo.cpp
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
using VS = vector<string>;
using VVS = vector<VS>;


/*
RESULT: Accept
TIME:    504ms    BEAT:  5.56%    O(n) = 
MEMORY: 32.2MB    BEAT: 47.58%    O(n) = 
USED TIME: 22:32
LAST EDIT TIME: 2021年4月9日21:58:21
Description: 又臭又长。
*/

class TripleInOne {
public:
    VI st;
    int N;
    TripleInOne(int stackSize) {
        st.resize(stackSize * 3, -1);
        N = stackSize;
    }
    
    void push(int stackNum, int value) {
        int l = stackNum * N, r = stackNum * N + N - 1;
        FOR(i, l, r + 1) {
            if (st[i] == -1) {
                st[i] = value;
                break;
            }
        }
    }
    
    int pop(int stackNum) {
        int l = stackNum * N, r = stackNum * N + N - 1;
        for (int i = r; i >= l; i --) {
            if (st[i] != -1) {
                int tmp = st[i];
                st[i] = -1;
                return tmp;
            }
        }
        return -1;
    }
    
    int peek(int stackNum) {
        int l = stackNum * N, r = stackNum * N + N - 1;
        for (int i = r; i >= l; i --) {
            if (st[i] != -1) {
                return st[i];
            }
        }
        return -1;
    }
    
    bool isEmpty(int stackNum) {
        if (N == 0) return true;
        if (st[stackNum * N] == -1) return true;
        else return false;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */