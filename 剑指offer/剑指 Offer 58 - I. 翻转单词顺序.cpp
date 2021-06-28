/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-06 20:16:46
 * @LastEditTime: 2021-06-28 16:52:34
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 58 - I. 翻转单词顺序.cpp
 */

/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2021-04-05 20:05:57
 * @LastEditTime: 2021-06-28 15:09:38
 * @FilePath: \Leetcode\ACRush.cpp
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
TIME:   4ms    BEAT: 90.68%    O(n) = 
MEMORY: 9MB    BEAT: 24.89%    O(n) = 
LAST EDIT TIME: 2021年6月28日16:52:18
Description: 
*/

class Solution {
public:
    string reverseWords(string s) {
        VS m;
        int l = 0, r = 0, n = s.length();
        while (s[r] == ' ') {
            r ++;
            l ++;
        }
        while (r < n) {
            while (r < n && s[r] != ' ') r ++;
            if (s[l] != ' ')m.push_back(s.substr(l, r - l));
            l = r + 1;
            r ++;
        }
        string res = "";
        RREP(i, m.size()) {
            res += i != 0 ? (m[i] + " ") : m[i];
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = n
MEMORY: 8.5MB    BEAT:  58.34%    O(n) = 1
Description: 
*/

class Solution {
public:
    string reverseWords(string s) {
        int r = s.length() - 1;
        int l = r;
        string res;
        for (int l = s.length() - 1; l >= 0; l --) {
            if (s[l] == ' ' && l == r) {
                r --;
            }
            else if (s[l] == ' ' && l != r) {
                res += s.substr(l + 1, r - (l + 1) + 1);
                res += ' ';
                r = l - 1;
            }
            else if (l == 0 && l != ' ') {
                res += s.substr(l, r - l + 1);
                return res;
            }
        }
        return res.substr(0, res.length() - 1);
    }
};


int main() {
    Solution sol;
    // string ans = sol.reverseWords("  hello world!  ");
    // string ans = sol.reverseWords("the sky is blue");
    string ans = sol.reverseWords("a good   example");
    cout << ans << endl;
    system("pause");
    return 0;
}
