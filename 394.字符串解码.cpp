/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-28 10:33:20
 * @LastEditTime: 2021-05-28 15:27:13
 * @FilePath: \Leetcode\394.字符串解码.cpp
 */
/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start

/*
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ████━████ ┃+
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
TIME:     4ms    BEAT: 35.48%    O(n) = 
MEMORY: 6.5MB    BEAT: 38.77%    O(n) = 
LAST EDIT TIME: 2021年5月28日15:26:53
Description: 
*/

class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> alpha;
        int idx = 0;
        while (idx < SZ(s)) {
            if (s[idx] >= '0' && s[idx] <= '9') {
                int a = 0;
                while (s[idx] >= '0' && s[idx] <= '9') {
                    a = a * 10 + (s[idx] -'0');
                    idx ++;
                }
                nums.push(a);
                continue;
            }
            else if (s[idx] == '[' || (s[idx] >= 'a' && s[idx] <= 'z')) {
                string tmp = "";
                tmp = tmp + s[idx];
                alpha.push(tmp);
                idx ++;
            }
            else {
                int times = nums.top();
                nums.pop();
                string res = "";
                while (alpha.top() != "[") {
                    res += alpha.top();
                    alpha.pop();
                }
                // reverse(ALL(res));
                alpha.pop();
                string tmp = "";
                REP(i, times) tmp += res;
                alpha.push(tmp);
                idx ++;
            }
        }
        string res = "";
        while (!alpha.empty()) {
            res += alpha.top();
            alpha.pop();
        }
        reverse(ALL(res));
        return res;
    }
};


int main() {
    Solution sol;
    // auto ans = sol.decodeString("2[abc]3[cd]ef");
    auto ans = sol.decodeString("100[a]2[bc]");
    cout << ans << endl;
    system("pause");
    return 0;
}
// @lc code=end

