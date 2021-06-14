/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-11 20:34:52
 * @LastEditTime: 2021-06-11 08:47:59
 * @FilePath: \Leetcode\279. Perfect Squares.cpp
 */
/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
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
TIME:    108ms    BEAT: 79.29%    O(n) = 
MEMORY: 11.8MB    BEAT: 16.65%    O(n) = 
LAST EDIT TIME: 2021年3月17日15:18:0
Description: BFS
*/

class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<int> dist(n + 1, INT_MAX);    // 所有点到零点的距离。
        
        q.push(0);
        dist[0] = 0;

        while (q.size()) {
            int num = q.front();
            q.pop();

            if (num == n) return dist[num];
            for (int i = 1; i * i + num <= n; i ++) {
                int tmp = i * i + num;
                if (dist[tmp] > dist[num] + 1) {
                    dist[tmp] = dist[num] + 1;
                    q.push(tmp);
                }
            }
        }

        return 0;
    }
};


/*
RESULT: Accept
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
LAST EDIT TIME: 2021年3月11日21:10:13
Description: BUG？超级大BUG？这里能过，Leetcode报错？草？这和322题有什么区别？
*/

// class Solution {
// public:
//     int maxNum;
//     vector<int> count;
//     int numSquares(int n) {
//         maxNum = sqrt(n);
//         count.resize(n + 1, 0);
//         return backTrack(n);
//     }

//     int backTrack(int remain) {
//         if (remain == 0) return 0;
//         if (remain == -1) return -1;

//         if (count[remain] != 0) return count[remain];

//         int Min = INT_MAX;
//         for (int i = 1; i <= maxNum; i ++) {
//             int res = backTrack(remain - i * i);
//             if (res >= 0 && res < Min) {
//                 Min = res + 1;
//             }
//         }
//         count[remain] = Min == INT_MAX ? -1 : Min;
//         return count[remain];
//     }
// };


int main() {
    Solution sol;
    int ans = sol.numSquares(1000);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

