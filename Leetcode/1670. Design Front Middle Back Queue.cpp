/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-19 13:29:09
 * @LastEditTime: 2021-04-19 13:54:09
 * @FilePath: \Leetcode\1670. Design Front Middle Back Queue.cpp
 */
/*
 * @lc app=leetcode.cn id=1670 lang=cpp
 *
 * [1670] 设计前中后队列
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
TIME:     36ms    BEAT: 92.86%    O(n) = 
MEMORY: 19.5MB    BEAT: 89.93%    O(n) = 
USED TIME: 05:25
LAST EDIT TIME: 2021年4月19日13:53:11
Description: 模拟
*/

class FrontMiddleBackQueue {
public:
    VI q;

    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        q.insert(q.begin(), val);
    }
    
    void pushMiddle(int val) {
        int idx = SZ(q) / 2;
        q.insert(q.begin() + idx, val);
    }
    
    void pushBack(int val) {
        q.PB(val);
    }
    
    int popFront() {
        if (SZ(q)) {
            int x = q.front();
            q.erase(q.begin());
            return x;
        }
        return -1;
    }
    
    int popMiddle() {
        if (SZ(q)) {
            int idx = (SZ(q) - 1) / 2;
            int x = q[idx];
            q.erase(q.begin() + idx);
            return x;
        }
        return -1;
    }
    
    int popBack() {
        if (SZ(q)) {
            int x = q.back();
            q.pop_back();
            return x;
        }
        return -1;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end

