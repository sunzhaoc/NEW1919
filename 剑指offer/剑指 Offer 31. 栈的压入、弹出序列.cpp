/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-05 10:22:59
 * @LastEditTime: 2021-07-10 15:13:38
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 31. 栈的压入、弹出序列.cpp
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
TIME:     12ms    BEAT: 51.49%    O(n) = 
MEMORY: 14.8MB    BEAT: 13.89%    O(n) = 
LAST EDIT TIME: 2021年7月10日15:13:25
Description: 
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (!pushed.size()) return true;
        int idx1 = 0, idx2 = 0;
        stack<int> st;

        while (pushed[idx1] != popped[idx2]) st.push(pushed[idx1 ++]);
        st.push(pushed[idx1 ++]);

        while (idx2 < SZ(popped)) {
            if (st.size() && popped[idx2] == st.top()) {
                st.pop();
                idx2 ++;
            }

            else if (idx1 < SZ(pushed) && pushed[idx1] == popped[idx2]) {
                idx1 ++;
                idx2 ++;
            }

            else if (idx1 < SZ(pushed)) {
                st.push(pushed[idx1]);
                idx1 ++;
            }

            else return false;
        }
        return true;
    }
};


/*
RESULT: Accept
TIME:   16ms    BEAT: 80.40%    O(n) = n
MEMORY: 15MB    BEAT: 82.48%    O(n) = n
USED TIME: 44:33
Description: 
*/

// class Solution {
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         int push_point = 0, pop_point = 0;
//         stack<int> stack1;

//         for (int i = 0; i < pushed.size(); i ++) {
//             if (pushed[push_point] == popped[0]) {
//                 pop_point ++;
//                 push_point ++;
//                 break;
//             }
//             stack1.push(pushed[push_point]);
//             push_point ++;
//         }

//         while (pop_point < popped.size()) {
//             if (!stack1.empty() && popped[pop_point] == stack1.top()) {
//                 stack1.pop();
//                 pop_point ++;
//             }
//             else if (push_point <= pushed.size() - 1 && pushed[push_point] == popped[pop_point]) {
//                 push_point ++;
//                 pop_point ++;
//             }
//             else if (push_point <= pushed.size() - 1) {
//                 stack1.push(pushed[push_point]);
//                 push_point ++;
//             }
//             else return false;
//         }
//         return true;
//     }
// };


int main() {
    Solution sol;
    // vector<int> pushed = {1, 2, 3, 4, 5}, popped = {4, 5, 3, 2, 1};
    // vector<int> pushed = {1, 2, 3, 4, 5}, popped = {4, 3, 5, 1, 2};
    // vector<int> pushed = {1, 0}, popped = {1, 0};
    // vector<int> pushed = {0, 2, 1}, popped = {0, 1, 2};
    vector<int> pushed = {2, 0, 1}, popped = {2, 1, 0};

    bool ans = sol.validateStackSequences(pushed, popped);
    cout << ans << endl;
    system("pause");
    return 0;
}