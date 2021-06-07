/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-18 22:04:37
 * @LastEditTime: 2021-06-03 08:31:11
 * @FilePath: \Leetcode\525. 连续数组.cpp
 */
/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
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
TIME:    160ms    BEAT: 38.08%    O(n) = 
MEMORY: 81.9MB    BEAT: 21.96%    O(n) =  
LAST EDIT TIME: 2021年6月3日8:31:11
Description: 
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int& x: nums) if (x == 0) x = -1;
        unordered_map<int, int> m;
        m[0] = -1;
        int max_len = 0, sum = 0;
        REP(i, SZ(nums)) {
            sum += nums[i];

            auto it = m.find(sum);
            if (it != m.end()) ckmax(max_len, i - it->second);
            else m[sum] = i;
        }
        return max_len;
    }
};


/*
RESULT: Accept
TIME:    144ms    BEAT: 76.40%    O(n) = 
MEMORY: 76.9MB    BEAT: 76.40%    O(n) = 
USED TIME: 06:08
LAST EDIT TIME: 2021年3月18日20:55:45
Description: 二刷
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 0) nums[i] = -1;
        }

        unordered_map<int, int> map;

        map[0] = -1;
        int max_len = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];

            auto it = map.find(sum);
            if (it != map.end()) {
                max_len = max(max_len, i - it->second);
            }
            else {
                map[sum] = i;
            }
        }
        return max_len;
    }
};


/*
RESULT: Accept
TIME:   124ms    BEAT: 99.80%    O(n) = n
MEMORY:  77MB    BEAT: 93.18%    O(n) = 1
LAST EDIT TIME: 2021年1月19日10:3:0
Description: 前缀和。把所有的0都换成-1，这个方法有点妙。
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }

        int max_len = 0;

        unordered_map<int, int> map;
        map[0] = -1;

        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];

            auto it = map.find(sum);
            if (it != map.end()) {
                max_len = max(max_len, i - it->second);
            }
            else {
                map[sum] = i;
            }
        }

        return max_len;
    }
};


int main() {
    Solution sol;
    // vector<int> nums = {0,1};
    // vector<int> nums = {0,1,0};
    // vector<int> nums = {1,1,1,1,1,1,0,1,0,1,0};
    vector<int> nums = {1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0};
    int ans = sol.findMaxLength(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

