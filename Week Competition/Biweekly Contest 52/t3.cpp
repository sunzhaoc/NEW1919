/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-25 10:14:44
 * @LastEditTime: 2021-05-15 23:13:49
 * @FilePath: \Leetcode\Week Competition\Biweekly Contest 52\t3.cpp
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
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = SZ(box), n = SZ(box[0]);
        vector<vector<char>> res(n, vector<char>(m));
        REP(i, m) {
            REP(j, n) {
                res[j][m - 1 - i] = box[i][j];
            }
        }
        
        REP(j, m) { // col
            int rock = 0, blank = 0;
            REP(i, n) { // row
                if (i == n - 1 && res[i][j] != '*') {
                    if (res[i][j] == '#') rock ++;
                    else blank ++;
                    int k = i;
                    while (rock) {
                        res[k][j] = '#';
                        rock --;
                        k --;
                    }
                    while (blank) {
                        res[k][j] = '.';
                        blank --;
                        k --;
                    }
                }
                
                else if (res[i][j] == '#') rock ++;
                else if (res[i][j] == '.') blank ++;
                else if (res[i][j] == '*') {
                    int k = i - 1;
                    while (rock) {
                        res[k][j] = '#';
                        rock --;
                        k --;
                    }
                    while (blank) {
                        res[k][j] = '.';
                        blank --;
                        k --;
                    }
                }

            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<vector<char>> box = {{'#','.','#'}};
    // vector<vector<char>> box = {{'#','.','*','.'},{'#','#','*','.'}};
    auto ans = sol.rotateTheBox(box);
    // cout << ans << endl;
    // REP(i, SZ(ans)) cout << ans[i] << endl;
    REP(i, SZ(ans)) REP(j, SZ(ans[0])) cout << ans[i][j] << endl;
    system("pause");
    return 0;
}