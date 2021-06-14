/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2021-04-25 10:19:28
 * @LastEditTime: 2021-06-12 23:40:41
 * @FilePath: \Leetcode\Week Competition\Biweekly Contest 54\t3.cpp
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


class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> row_pre(row, vector<int>(col + 1, 0));
        for (int r = 0; r < row; r ++) for (int c = 0; c < col; c ++) row_pre[r][c + 1] = row_pre[r][c] + grid[r][c];
        vector<vector<int>> col_pre(col, vector<int>(row + 1, 0));
        for (int c = 0; c < col; c ++) for (int r = 0; r < row; r ++) col_pre[c][r + 1] = col_pre[c][r] + grid[r][c];

        int res = 1;
        for (int r = 0; r < row; r ++){
            for (int c = 0; c < col; c ++) {
                for(int k = res + 1; k < 51; k ++) {
                    int nr = r + k - 1, nc = c + k - 1;
                    if (nr >= row || nc >= col) break;
                    
                    bool ok = true;
                    int cur_sum = row_pre[r][nc + 1] - row_pre[r][c];
                    for (int rr = r + 1; rr < nr + 1; rr ++) {
                        if (row_pre[rr][nc + 1] - row_pre[rr][c] != cur_sum) {
                            ok = false;
                            break;
                        }
                    }                 
                    if (ok == true) {
                        FOR(cc, c, nc + 1) {
                            if (col_pre[cc][nr + 1] - col_pre[cc][r] != cur_sum) {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if (ok == true) {
                        int pos_sum = grid[r][c], pr = r, pc = c;
                        REP(tmp, k - 1) {
                            pr ++, pc ++;
                            pos_sum += grid[pr][pc];
                        }
                        if (pos_sum != cur_sum) ok = false;
                    }
                    if (ok == true) {
                        int neg_sum = grid[r][nc];
                        int ner = r;
                        int nec = nc;
                        REP(tmp, k - 1) {
                            ner ++, nec --;
                            neg_sum += grid[ner][nec];
                        }
                        if (neg_sum != cur_sum) ok = false;
                    }
                    if (ok == true) ckmax(res, k);
                }
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    // VI nums = {};
    // VVI nums = {};
    VVI nums = {{7,1,4,5,6},{2,5,1,6,4},{1,5,4,3,2},{1,2,7,3,4}};
    auto ans = sol.largestMagicSquare(nums);
    // cout << ans << endl;
    // REP(i, SZ(ans)) cout << ans[i] << endl;
    // REP(i, SZ(ans)) REP(j, SZ(ans[0])) cout << ans[i][j] << endl;
    system("pause");
    return 0;
}