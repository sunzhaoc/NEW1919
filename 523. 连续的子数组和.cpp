/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-15 12:37:38
 * @LastEditTime: 2021-06-02 09:20:43
 * @FilePath: \Leetcode\523. 连续的子数组和.cpp
 */
/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
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
TIME:    184ms    BEAT: %    O(n) = 
MEMORY: 94.2MB    BEAT: %    O(n) = 
LAST EDIT TIME: 2021年6月2日9:20:30
Description: 
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (SZ(nums) < 2) return false;
        int sum = 0;
        unordered_map<int, int> m;
        REP(i, SZ(nums)) {
            sum = (sum + nums[i]) % k;
            if (i > 0 && sum == 0) return true;
            auto it = m.find(sum);
            if (it == m.end()) m[sum] = i;
            else if (i - it->second >= 2) return true;
        }
        return false;
    }
};


/*
RESULT: Accept
TIME:     28ms    BEAT: 100.00%    O(n) = n
MEMORY: 25.5MB    BEAT:  85.35%    O(n) = min(n, k)
USED TIME: 53:03
LAST EDIT TIME: 2021年1月15日13:33:40
Description: 哈希表 + 前缀和。 我反正不知道怎么写了那么久。各种边界条件要注意。
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // 小于2直接跳过
        if (nums.size() < 2) return false;

        // 因为分母不能为0，故要单独讨论。注意题目nums均>=0,故只有0 + 0 = 0！！！
        if (k == 0) {
            for (int i = 1; i < nums.size(); i ++) {
                if (nums[i - 1] == nums[i] && nums[i] == 0) {
                    return true;
                }
            }
            return false;
        }
        

        int sum = 0;
        unordered_map<int, int> map; 
        for (int i = 0; i < nums.size(); i ++) {
            sum = (sum + nums[i]) % k;

            // 避免第一个是0，0是任何数的倍数，但长度为1，不满足。
            if (i > 0 && sum == 0) return true;
            else {
                auto it = map.find(sum);
                // Not found
                if (it == map.end()) {
                    map[sum] = i;
                }
                // Find
                else {
                    //
                    if (i - it->second >= 2){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};


int main() {
    Solution sol;
    // vector<int> nums = {23,2,4,6,7}; int k = -6; // true
    // vector<int> nums = {1,0,1,0,1}; int k = 4; // false
    // vector<int> nums = {0,1}; int k = 1;
    // vector<int> nums = {0}; int k = -1; // false
    // vector<int> nums = {0,1}; int k = 1; // true
    // vector<int> nums = {0,0, 0, 0, 0, 0 }; int k = 1; // true
    // vector<int> nums = {1,0}; int k = 2; // false
    vector<int> nums = {0,0}; int k = 0; // false
    // vector<int> nums = {0,0}; int k = 1; // true
    // vector<int> nums = {0,1,0,3,0,4,0,4,0}; int k = 5; // false
    
    bool ans = sol.checkSubarraySum(nums, k);
    cout << ans << endl;
    
    system("pause");
    return 0;
}
// @lc code=end

