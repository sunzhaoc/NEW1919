/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-06 17:00:42
 * @LastEditTime: 2021-06-28 15:32:08
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 56 - I. 数组中数字出现的次数.cpp
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
TIME:     16ms    BEAT: 91.88%    O(n) = 
MEMORY: 15.7MB    BEAT: 47.28%    O(n) = 
LAST EDIT TIME: 2021年6月28日15:26:11
Description: 
*/

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0;
        for (int& i: nums) x ^= i;
        x &= (- x);

        int a = 0, b = 0;
        for (int& i: nums) {
            if (i & x) a ^= i;
            else b ^= i;
        }
        return {a, b};
    }
};


/*
RESULT: Accept
TIME:     36ms    BEAT: 90.05%    O(n) = 
MEMORY: 16.1MB    BEAT: 43.15%    O(n) = 
Description: 分组异或运算。
*/

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0;

        for (int i: nums) {
            x ^= i;
        }

        int first = 1;
        while (!(first & x)) {
            first <<= 1;
        }
        
        int a = 0, b = 0;
        for (int i: nums) {
            if (i & first) a ^= i;
            else b ^= i;
        }

        return {a, b};
    }
};


int main() {
    Solution sol;
    vector<int> nums = {4, 1, 4, 6};
    vector<int> ans = sol.singleNumbers(nums);
    system("pause");
    return 0;
}


