/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-09 10:01:46
 * @LastEditTime: 2021-04-09 11:05:05
 * @FilePath: \Leetcode\1415.The k-th Lexicographical String of All Happy Strings of Length n.cpp
 */
/*
 * @lc app=leetcode.cn id=1415 lang=cpp
 *
 * [1415] 长度为 n 的开心字符串中字典序第 k 小的字符串
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
TIME:     4ms    BEAT: 74.66%    O(n) = 
MEMORY: 5.9MB    BEAT: 73.30%    O(n) = 
LAST EDIT TIME: 2021年4月9日11:0:7
Description: 优化代码。
*/

class Solution {
public:
    int cnt = 0;
    int K, N;
    string ans;
    string nums = "abc";
    string getHappyString(int n, int k) {
        K = k;
        N = n;
        string tmp = "";
        backTrack(tmp);
        return ans;
    }

    void backTrack(string& cur) {
        if (LENGTH(cur) == N) {
            if (++ cnt == K) ans = cur;
            return;
        }

        char cur_back = LENGTH(cur) == 0 ? 'z' : cur[LENGTH(cur) - 1];
        // 改成这行就会错。可能是因为当cur = "" 时。cur[-1]的索引会报错，但这并不能解释为什么在IDE里不会报错啊。
        // char cur_back = cur[LENGTH(cur) - 1];

        REP(i, 3) {
            if (nums[i] == cur_back) continue;
            cur += nums[i];
            backTrack(cur);
            if (cnt == K) return;
            cur = cur.substr(0, SZ(cur) - 1);
        }
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 74.66%    O(n) = 
MEMORY: 8.1MB    BEAT: 41.69%    O(n) = 
USED TIME: 22:43
LAST EDIT TIME: 2021年4月9日10:25:46
Description: 
*/

// class Solution {
// public:
//     int cnt = 0;
//     int K;
//     int N;
//     VS ans;
//     string nums = "abc";
//     string getHappyString(int n, int k) {
//         K = k;
//         N = n;
//         string tmp = "";
//         backTrack(tmp);
//         if (cnt < k) return "";
//         return ans[k - 1];
//     }

//     void backTrack(string& cur) {
//         if (cnt == K) return;
//         if (LENGTH(cur) == N) {
//             ans.PB(cur);
//             cnt ++;
//             return;
//         }
//         if (cur == "") {
//             REP(i, 3) {
//                 cur += nums[i];
//                 backTrack(cur);
//                         if (cnt == K) return;
//                 cur = cur.substr(0, LENGTH(cur) - 1);
//             }
//         }
//         else if (cur[LENGTH(cur) - 1] == 'a') {
//             cur += "b";
//             backTrack(cur);
//                     if (cnt == K) return;
//             cur = cur.substr(0, LENGTH(cur) - 1);
//             cur += "c";
//             backTrack(cur);
//                     if (cnt == K) return;
//             cur = cur.substr(0, LENGTH(cur) - 1);
//         } 
//         else if (cur[LENGTH(cur) - 1] == 'b') {
//             cur += "a";
//             backTrack(cur);
//                     if (cnt == K) return;
//             cur = cur.substr(0, LENGTH(cur) - 1);
//             cur += "c";
//             backTrack(cur);
//                     if (cnt == K) return;
//             cur = cur.substr(0, LENGTH(cur) - 1);
//         }
//         else if (cur[LENGTH(cur) - 1] == 'c') {
//             cur += "a";
//             backTrack(cur);        
//             if (cnt == K) return;
//             cur = cur.substr(0, LENGTH(cur) - 1);
//             cur += "b";
//             backTrack(cur);
//                     if (cnt == K) return;
//             cur = cur.substr(0, LENGTH(cur) - 1);
//         }
//     }
// };


int main() {
    Solution sol;
    auto ans = sol.getHappyString(1, 4);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

