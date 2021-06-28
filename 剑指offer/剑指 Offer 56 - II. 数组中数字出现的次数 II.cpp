/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-06 17:11:17
 * @LastEditTime: 2021-06-28 16:13:46
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 56 - II. 数组中数字出现的次数 II.cpp
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
TIME:     40ms    BEAT: 76.51%    O(n) = 
MEMORY: 15.7MB    BEAT: 59.70%    O(n) = 
LAST EDIT TIME: 2021年6月28日15:35:3
Description: 
*/

class Solution {
public:
    int quick_pow(int a, int k) {
        if (k == 0) return 1;
        int res = quick_pow(a, k / 2);
        return k % 2 == 0 ? res * res : res * res * 2;
    }
    int singleNumber(vector<int>& nums) {
        long long b[32];
        memset(b, 0, sizeof b);
        for (int& x: nums) {
            for (int i = 0; i < 32; i ++) {
                b[i] += x & (1 << i);
            }
        }

        int res = 0;
        for (int i = 0; i < 32; i ++) {
            if (b[i] % 3 != 0)res += quick_pow(2, i);
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     88ms    BEAT: %    O(n) = 
MEMORY: 16.6MB    BEAT: %    O(n) = 
LAST EDIT TIME: 2021年01月06日18:20
Description: 
*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> binary(32, 0);

        for (int i: nums) {
            // for (int j = 0; j < 32; j ++) {
            for (int j = 31; j >= 0; j --) {
                binary[j] += i & 1;
                i >>= 1;
            }
        }

        int res;

        // for (int i = 0; i < 32; i ++) {
            // if (binary[i] % 3 != 0) res += pow(2, i);
        for (int i = 31; i >= 0; i --) {
            if (binary[i] % 3 != 0) res += pow(2, (31 - i));
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {4, 1, 4, 4};
    vector<int> ans = sol.singleNumber(nums);
    system("pause");
    return 0;
}