/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-10 08:27:58
 * @LastEditTime: 2021-04-27 12:49:28
 * @FilePath: \Leetcode\224. Basic Calculator.cpp
 */
/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
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
TIME:     68ms    BEAT: 7.20%    O(n) = 
MEMORY: 27.4MB    BEAT: 7.63%    O(n) = 
LAST EDIT TIME: 2021年4月27日12:48:42
Description: 逆波兰表达式。
*/

class Solution {
public:
    int calculate(string s) {
        // 中缀转后缀
        stack<char> sign;
        vector<string> postExpres;
        int idx = 0;
        while (idx < s.length()) {
            if ((idx == 0 || s[idx - 1] == '(') && (s[idx] == '+' || s[idx] == '-')) postExpres.push_back("0");
            // 若是空格，跳过
            if (s[idx] == ' ') {
                idx ++;
                continue;
            }

            // 若是数字，直接放入。
            if (isdigit(s[idx])) {
                LL sum = 0;
                while (idx < s.length() && isdigit(s[idx])) sum = sum * 10 + s[idx ++] - '0';
                postExpres.push_back(to_string(sum));
                continue;
            }

            // 若是符号
            if (sign.empty() || s[idx] == '(' || s[idx] == '*' || s[idx] == '/') {
                sign.push(s[idx ++]);
                continue;
            }
            if (s[idx] == ')') {
                while (sign.size() && sign.top() != '(') {
                    string tmp = "";
                    tmp += sign.top();
                    postExpres.push_back(tmp);
                    sign.pop();
                }
                sign.pop();
                idx ++;
                continue;
            }
            if (s[idx] == '+' || s[idx] == '-') {
                while (sign.size() && sign.top() != '(') {
                    string tmp = "";
                    tmp += sign.top();
                    postExpres.push_back(tmp);
                    sign.pop();
                }
                sign.push(s[idx ++]);
                continue;
            }
        }
    
        while (sign.size()) {
            string tmp = "";
            tmp += sign.top();
            postExpres.push_back(tmp);
            sign.pop();
        }

        // 计算逆波兰表达式
        int res = 0;
        stack<int> st;
        for (string& ch: postExpres) {
            if (isdigit(ch[0])) {
                st.push(stoi(ch));
                continue;
            }
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (ch == "+") st.push(a + b);
            else if (ch == "-") st.push(a - b);
            else if (ch == "*") st.push(a * b);
            else st.push(a / b);            
        }
        return st.top();
    }
};


/*
RESULT: Accept
TIME:     8ms    BEAT: 92.89%    O(n) = n
MEMORY: 7.9MB    BEAT: 80.31%    O(n) = n
USED TIME: 
LAST EDIT TIME: 2021年3月10日8:52:59
Description: 得稍微仔细想想。
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> ops;
        ops.push(1);
        int sign = 1;
        int res = 0;
        int i = 0;

        while (i < s.length()) {
            if (s[i] == ' ') {
                i ++;
            }
            else if (s[i] == '+') {
                sign = ops.top();
                i ++;
            }
            else if (s[i] == '-') {
                sign = - ops.top();
                i ++;
            }
            else if (s[i] == '(') {
                ops.push(sign);
                i ++;
            }
            else if (s[i] == ')') {
                ops.pop();
                i ++;
            }
            else {
                long num = 0;
                while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i ++;
                }
                res += sign * num;
            }
        }

        return res;
    }
};

// @lc code=end

