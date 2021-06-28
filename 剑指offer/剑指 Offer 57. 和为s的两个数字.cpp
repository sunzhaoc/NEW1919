/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-06 18:41:29
 * @LastEditTime: 2021-06-28 16:23:06
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 57. 和为s的两个数字.cpp
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
TIME:    224ms    BEAT: 58.69%    O(n) = n
MEMORY: 98.2MB    BEAT: 77.20%    O(n) = 1
LAST EDIT TIME: 2021年6月28日16:17:20
Description:  
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] == target) return {nums[l], nums[r]};
            if (nums[l] + nums[r] > target) r --;
            else l ++;
        }
        return {-1, -1};
    }
};


/*
RESULT: Accept
TIME:    452ms    BEAT: 40.30%    O(n) = n
MEMORY: 98.6MB    BEAT: 40.19%    O(n) = 1
Description: 对撞双指针。Easy。
*/

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int l = 0, r = nums.size() - 1;
        
//         while (1) {
//             if (nums[l] + nums[r] == target) return {nums[l], nums[r]};
//             if (nums[l] + nums[r] > target) r --;
//             else l ++;
//         }
//     }
// };


int main() {
    Solution sol;
    // vector<int> nums = {2,7,11,15};
    vector<int> nums = {14,15,16,22,53,60};
    vector<int> ans = sol.twoSum(nums, 76);
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}