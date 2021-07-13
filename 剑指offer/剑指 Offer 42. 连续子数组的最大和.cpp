/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-05 16:18:41
 * @LastEditTime: 2021-07-12 16:13:55
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 42. 连续子数组的最大和.cpp
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
TIME:     24ms    BEAT: 67.82%    O(n) = 
MEMORY: 22.4MB    BEAT: 69.14%    O(n) = 
LAST EDIT TIME: 2021年7月12日16:12:51
Description: 
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (SZ(nums) == 1) return nums[0];
        int tmp = nums[0], res = nums[0];
        FOR(i, 1, SZ(nums)) {
            tmp = max(nums[i], tmp + nums[i]);
            res = max(res, tmp);
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     20ms    BEAT: 87.39%    O(n) = n
MEMORY: 22.2MB    BEAT: 96.33%    O(n) = 1
LAST EDIT TIME: 2021年6月24日9:11:0
Description: DP优化
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int tmp = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            tmp = max(nums[i], tmp + nums[i]);
            res = max(res, tmp);
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     28ms    BEAT: 42.70%    O(n) = n
MEMORY: 23.1MB    BEAT:  5.13%    O(n) = n
LAST EDIT TIME: 2021年6月24日9:6:12
Description: DP
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     48ms    BEAT: 60.26%    O(n) = n
MEMORY: 22.8MB    BEAT: 73.61%    O(n) = 1
Description: 优化了一下。没有用数组存储。
*/

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         if (nums.size() == 1) return nums[0];
//         int l = nums[0], r;
//         int res = l;

//         for (int i = 1; i < nums.size(); i ++) {
//             r = max(nums[i], l + nums[i]);
//             res = res < r ? r : res;
//             l = r;
//         }
//         return res;
//     }
// };


/*
RESULT: Accept
TIME:     48ms    BEAT: 60.20%    O(n) = n
MEMORY: 23.4MB    BEAT: 14.57%    O(n) = n
USED TIME: 16:57
Description: 
*/

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         if (nums.size() == 1) return nums[0];
//         vector<int> dp(nums.size());
//         dp[0] = nums[0];
//         int res = dp[0];
//         for (int i = 1; i < nums.size(); i ++) {
//             dp[i] = max(nums[i], dp[i - 1] + nums[i]);
//             res = res < dp[i] ? dp[i] : res;
//         }
//         return res;
//     }
// };


int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = sol.maxSubArray(nums);
    cout << ans << endl;
    system("pause");
    return 0;
}

