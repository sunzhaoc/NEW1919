/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2021-04-25 10:19:28
 * @LastEditTime: 2021-07-10 23:55:00
 * @FilePath: \Leetcode\Week Competition\Biweekly Contest 56\t3.cpp
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
    bool sumGame(string num) {
        LL sumL = 0, sumR = 0;
        REP(i, SZ(num) / 2) if (num[i] != '?') sumL += num[i] - '0';
        FOR(i, SZ(num) / 2, SZ(num)) if (num[i] != '?') sumR += num[i] - '0';

        int cnt_l = 0, cnt_r = 0; 
        REP(i, SZ(num) / 2) if (num[i] == '?') cnt_l ++;
        FOR(i, SZ(num) / 2, SZ(num)) if (num[i] == '?') cnt_r ++;

        if (cnt_l + cnt_r == 0) {
            if (sumL == sumR) return false;
            return true;
        }
        
        int step = 0;
        while (cnt_r + cnt_l) {
            if (step % 2 == 0) {// alice;
                if (sumL > sumR) {
                    if (cnt_l == 0) {
                        if (sumL > sumR + 9 * cnt_r) return false; 
                        cnt_r --;
                    }
                    else {
                        cnt_l --;
                        sumL += 9;
                    }
                }
                else if (sumL < sumR) {
                    if (cnt_r == 0) {
                        if (sumR > sumL + 9 * cnt_l) return false;
                        cnt_l --;
                    }
                    else {
                        cnt_r--;
                        sumR += 9;
                    }
                }
            }

            else { // Bpb
                if (sumL > sumR) {
                    if (cnt_r == 0) {
                        return true;
                    }
                    else {
                        cnt_r --;
                        if (sumR + 9 < sumL) sumR += 9;
                        else sumR = sumL;
                    }
                }

                else if (sumL < sumR) {
                    if (cnt_l == 0) return true;
                    else {
                        cnt_l --;
                        if (sumL + 9 < sumR) sumL += 9;
                        else sumL = sumR;
                    }
                }
            }
            step ++;
        }
        if (sumR == sumL) return false;
        return true;
    }
};


int main() {
    Solution sol;
    string tmp = "?3295???";
    auto ans = sol.sumGame(tmp);
    // cout << ans << endl;
    // REP(i, SZ(ans)) cout << ans[i] << endl;
    // REP(i, SZ(ans)) REP(j, SZ(ans[0])) cout << ans[i][j] << endl;
    system("pause");
    return 0;
}