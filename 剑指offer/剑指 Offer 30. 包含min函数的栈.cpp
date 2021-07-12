/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-04 19:40:01
 * @LastEditTime: 2021-07-10 14:44:39
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 30. 包含min函数的栈.cpp
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
TIME:     28ms    BEAT: 42.17%    O(n) = 
MEMORY: 14.6MB    BEAT: 90.84%    O(n) = 
LAST EDIT TIME: 2021年7月10日14:44:38
Description: 
*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st1, st2;

    MinStack() {}
        
    void push(int x) {
        st1.push(x);
        if (st2.empty() || x <= st2.top()) st2.push(x);
    }
    
    void pop() {
        if (st1.top() == st2.top()) st2.pop();
        st1.pop();
    }
    
    int top() { return st1.top(); }
    
    int min() { return st2.top(); }
};


/*
RESULT: Accept
TIME:     48ms    BEAT: 22.92%    O(n) = 1
MEMORY: 15.2MB    BEAT: 43.19%    O(n) = 1
USED TIME: 06:10
Description: 双堆。
*/

// class MinStack {
// public:
//     /** initialize your data structure here. */
//     stack<int> stack1, stack2;
//     MinStack() {

//     }
    
//     void push(int x) {
//         stack1.push(x);
//         if (stack2.empty() || x <= stack2.top()) stack2.push(x);
//     }
    
//     void pop() {
//         if(stack1.top() == stack2.top()) stack2.pop();
//         stack1.pop();
//     }
    
//     int top() {
//         return stack1.top();
//     }
    
//     int min() {
//         return stack2.top()
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */