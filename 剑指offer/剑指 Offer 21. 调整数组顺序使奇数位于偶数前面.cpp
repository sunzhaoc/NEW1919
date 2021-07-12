/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-24 10:47:36
 * @LastEditTime: 2021-07-12 14:30:53
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 21. 调整数组顺序使奇数位于偶数前面.cpp
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
TIME:     20ms    BEAT: 81.50%    O(n) = 
MEMORY: 17.7MB    BEAT: 54.49%    O(n) = 
LAST EDIT TIME: 2021年7月12日14:30:37s
Description: 
*/

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = SZ(nums) - 1;
        while (l < r) {
            while (l < r && nums[l] % 2 == 1) l ++;
            while (l < r && nums[r] % 2 == 0) r --;
            if (l < r) {
                swap(nums[l], nums[r]);
            }
        }
        return nums;
    }
};


/*
RESULT: Accept
TIME:     24ms    BEAT: 55.71%    O(n) = 
MEMORY: 17.7MB    BEAT: 56.36%    O(n) = 
LAST EDIT TIME: 2021年6月21日19:34:25
Description: 双指针。
*/

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            while (l < r && nums[l] % 2 == 1) l ++;
            while (l < r && nums[r] % 2 == 0) r --;
            if (l < r) {
                swap(nums[l], nums[r]);
            }
        }
        return nums;
    }
};


/*
RESULT: Accept
TIME:     24ms    BEAT: 55.71%    O(n) = 
MEMORY: 17.8MB    BEAT: 12.57%    O(n) = 
LAST EDIT TIME: 2021年6月21日19:14:43
Description: 
*/

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = 0;
        while (r < nums.size()) {
            if (nums[r] % 2 == 1) {
                swap(nums[l], nums[r]);
                l ++;
            }
            r ++;
        }
        return nums;
    }
};


/*
RESULT: Accept
TIME:     44ms    BEAT: 48.31%    O(n) = 
MEMORY: 18.1MB    BEAT: 38.97%    O(n) = 
Description: 快慢双指针。
https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/solution/ti-jie-shou-wei-shuang-zhi-zhen-kuai-man-shuang-zh/
*/

// class Solution {
// public:
//     vector<int> exchange(vector<int>& nums) {
//         int low = 0, fast = 0;
//         while (fast < nums.size()) {
//             if (nums[fast] % 2 == 1) {
//                 swap(nums[fast], nums[low]);
//                 low ++;
//             }
//             fast ++;
//         }
//         return nums;
//     }
// };


/*
RESULT: Accept
TIME:   32ms    BEAT: 97.86%    O(n) = 
MEMORY: 18MB    BEAT: 54.82%    O(n) = 
Description: 本题要求在原数组中更改，故不能开辟新空间。使用首尾双指针。
*/

// class Solution {
// public:
//     vector<int> exchange(vector<int>& nums) {
//         int left = 0, right = nums.size() - 1;
        
//         while (left < right) {
//             if (nums[left] % 2 == 0 && nums[right] % 2 == 1)    swap(nums[left], nums[right]);
//             if (nums[left] % 2 == 1)    left ++;
//             if (nums[right] % 2 == 0)   right --;
//         }
//         return nums;
//     }
// };


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = sol.exchange(nums);
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}