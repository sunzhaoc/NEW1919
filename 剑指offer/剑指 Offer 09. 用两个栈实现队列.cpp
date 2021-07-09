/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-30 13:24:55
 * @LastEditTime: 2021-07-09 09:58:51
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 09. 用两个栈实现队列.cpp
 */

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
TIME:   244ms    BEAT: 99.78%    O(n) = 
MEMORY: 101MB    BEAT: 81.76%    O(n) = 
LAST EDIT TIME: 2021年7月9日9:58:15
Description: 三刷
*/

class CQueue {
public:
    stack<int> st1, st2;
    CQueue() {

    }
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        if (st2.size()) {
            int res = st2.top();
            st2.pop();
            return res;
        }
        
        if (st1.empty()) return -1;
        while (SZ(st1)) {
            st2.push(st1.top());
            st1.pop();
        }
        int res = st2.top();
        st2.pop();
        return res;
    }
};


/*
RESULT: Accept
TIME:   352ms    BEAT: 48.59%    O(n) = 
MEMORY: 101MB    BEAT: 92.75%    O(n) = 
LAST EDIT TIME: 2021年6月18日15:43:1
Description: 二刷。
*/

// class CQueue {
// public:
//     stack<int> st1, st2;
    
//     CQueue() {
//     }
    
//     void appendTail(int value) {
//         st1.push(value);
//     }
    
//     int deleteHead() {
//         if (st2.size()) {
//             int res = st2.top();
//             st2.pop();
//             return res;
//         }

//         if (st1.empty()) return -1;
//         while (st1.size()) {
//             st2.push(st1.top());
//             st1.pop();
//         }
//         int res = st2.top();
//         st2.pop();
//         return res;
//     }
// };


/*
RESULT: Accept
TIME:     620ms    BEAT:  7.91%    O(n) = 
MEMORY: 108.3MB    BEAT: 18.52%    O(n) = 
LAST EDIT TIME: 2021年6月18日15:37:31
Description: 二刷。
*/

// class CQueue {
// public:
//     stack<int> st1, st2;
    
//     CQueue() {
//     }
    
//     void appendTail(int value) {
//         st1.push(value);
//     }
    
//     int deleteHead() {
//         if (st1.empty()) return -1;

//         while (st1.size()) {
//             st2.push(st1.top());
//             st1.pop();
//         }
//         int res = st2.top();
//         st2.pop();
//         while (st2.size()) {
//             st1.push(st2.top());
//             st2.pop();
//         }
//         return res;
//     }
// };


/*
RESULT: Accept
TIME:     520ms    BEAT: 72.41%    O(n) = 1
MEMORY: 101.6MB    BEAT: 43.32%    O(n) = 1
Description: 
*/

// class CQueue {
// public:
//     stack<int> stack1, stack2;

//     CQueue() {

//     }
    
//     void appendTail(int value) {
//         stack1.push(value);
//     }

//     int deleteHead() {
//         if (!stack2.empty()) {
//             int ans = stack2.top();
//             stack2.pop();
//             return ans;
//         }

//         if (stack1.empty()) return -1;
//         while (!stack1.empty()) {
//             stack2.push(stack1.top());
//             stack1.pop();
//         }
//         int ans = stack2.top();
//         stack2.pop();
//         return ans;
//     }
// };

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */