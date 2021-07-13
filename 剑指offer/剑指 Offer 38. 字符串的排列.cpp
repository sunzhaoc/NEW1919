/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-24 14:22:36
 * @LastEditTime: 2021-07-12 15:19:11
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 38. 字符串的排列.cpp
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
TIME:     36ms    BEAT: 64.80%    O(n) = 
MEMORY: 19.9MB    BEAT: 55.86%    O(n) = 
LAST EDIT TIME: 
Description: 
*/

class Solution {
public:
    int n;
    vector<string> res;
    vector<string> permutation(string s) {
        n = SZ(s);
        sort(ALL(s));
        string path = "";
        dfs(s, path);
        return res;
    }

    void dfs(string& s, string& path) {
        if (SZ(path) == n) {
            res.PB(path);
            return;
        }
        REP(i, SZ(s)) {
            if (i == 0 || s[i] != s[i - 1]) {
                path += s[i];
                string tmpS = s.substr(0, i) + s.substr(i + 1);
                dfs(tmpS, path);
                path = path.substr(0, path.size() - 1);
            }
        }
    }
};


/*
RESULT: Accept
TIME:     36ms    BEAT: 79.63%    O(n) = 
MEMORY: 19.9MB    BEAT: 74.91%    O(n) = 
LAST EDIT TIME: 2021年6月22日8:48:6
Description: 回溯。
*/

class Solution {
public:
    int n;
    vector<string> res;
    vector<string> permutation(string str) {
        n = str.size();
        sort(str.begin(), str.end());
        string used = "";
        dfs(str, used);
        return res;
    }

    void dfs(string& unused, string& used) {
        if (used.size() == n) {
            res.push_back(used);
            return;
        }
        for (int i = 0; i < unused.size(); i ++) {
            if (i == 0 || unused[i] != unused[i - 1]) {
                used += unused[i];
                string tmp_unused = unused.substr(0, i) + unused.substr(i + 1);
                dfs(tmp_unused, used);
                used = used.substr(0, used.size() - 1);
            }
        }
    }
};


/*
RESULT: Accept
TIME:   132ms    BEAT: 52.74%    O(n) = 
MEMORY:  37MB    BEAT: 12.01%    O(n) = 
Description: 
*/

// class Solution {
// public:
//     vector<string> ans;
//     string s_copy;

//     vector<string> permutation(string s) {
//         s_copy = s;
//         dfs(0);
//         return ans;
//     }

// private:
//     void dfs(int x) {
//         if (x == s_copy.size() - 1) {
//             ans.push_back(s_copy);
//             return;
//         }

//         unordered_set<char> dic;
//         for (int i = x; i < s_copy.size(); i ++) {
//             if (dic.count(s_copy[i])) continue;
//             dic.insert(s_copy[i]);
//             swap(s_copy[i], s_copy[x]);
//             dfs(x + 1);
//             swap(s_copy[i], s_copy[x]);
//         }
//     }
// };


int main() {
    Solution sol;
    vector<string> ans = sol.permutation("abc");
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}