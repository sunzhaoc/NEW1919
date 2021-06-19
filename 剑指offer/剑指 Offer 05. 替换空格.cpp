/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2020-12-03 21:50:54
 * @LastEditTime: 2021-06-18 15:07:08
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 05. 替换空格.cpp
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
TIME:     4ms    BEAT: 31.49%    O(n) = n
MEMORY: 6.1MB    BEAT: 49.26%    O(n) = 1
LAST EDIT TIME: 2021年6月18日15:6:40
Description: 原地修改。二刷。
*/

class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0, n = s.length();
        for (char& ch: s) if (ch == ' ') cnt ++;

        s.resize(n + cnt * 2);
        for (int i = n - 1, j = s.size() - 1; i >= 0; i --, j --) {
            if (s[i] != ' ') s[j] = s[i];
            else {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            }
        }
        return s;
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = n
MEMORY: 6.1MB    BEAT:  67.30%    O(n) = n
LAST EDIT TIME: 2021年6月18日15:0:43
Description: 二刷
*/

class Solution {
public:
    string replaceSpace(string s) {
        string res = "";
        for (auto& ch: s) {
            if (ch != ' ') res += ch;
            else res += "%20";
        }
        return res;
    }
};


/*
RESULT: Accept
TIME: 0ms BEAT: 100.00%
MEMORY: 6.5MB BEAT: 14.32%
Description: 从前往后遍历数组，开辟一个新的字符串，遇到空格就append %20，希望能在原来的字符串上进行修改。
*/
// class Solution {
// public:
//     string replaceSpace(string s) {
//         string res = "";
//         for (int i = 0; i < s.size(); i++){
//             if (s[i] == ' ') res.append("%20");
//             else res += s[i];
//         }
//         return res;
//     }
// };


// int main(){
//     Solution sol;
//     string A = sol.replaceSpace("We are happy.");
//     cout << A << endl;
//     system("pause");
//     return 0;
// }
