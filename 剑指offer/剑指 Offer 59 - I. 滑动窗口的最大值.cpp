/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-07 10:30:58
 * @LastEditTime: 2021-05-20 11:16:16
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 59 - I. 滑动窗口的最大值.cpp
 */


/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-05 20:05:57
 * @LastEditTime: 2021-05-18 15:59:50
 * @FilePath: \Leetcode\ACRush.cpp
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
TIME:     24ms    BEAT: 59.10%    O(n) = 
MEMORY: 15.7MB    BEAT: 15.85%    O(n) = 
USED TIME: 07:49
LAST EDIT TIME: 2021年5月20日11:16:2
Description: 
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        VI res;
        deque<int> q;
        for (int l = 1 - k,  r = 0; r < SZ(nums); l ++, r ++) {
            if (l > 0 && nums[l - 1] == q.front()) q.pop_front();

            while (SZ(q) && nums[r] > q.front()) q.pop_front();
            while (SZ(q) && nums[r] > q.back()) q.pop_back();
            q.push_back(nums[r]);
            if (l >= 0) res.push_back(q.front());
        }
        return res;
    }
};

/*
RESULT: Accept
TIME:     56ms    BEAT: 32.33%    O(n) = 
MEMORY: 16.1MB    BEAT: 28.96%    O(n) = 
Description: 
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k) return {};
        int l = 1 - k, r = 0;

        deque<int> dq;
        vector<int> res;

        while (r < nums.size()) {
            if (l >= 1 && nums[l - 1] == dq[0]) dq.pop_front();

            while (!dq.empty() && dq[0] < nums[r]) dq.pop_front();
            while (!dq.empty() && dq[dq.size() - 1] < nums[r]) dq.pop_back();
            dq.push_back(nums[r]);

            if (l >= 0) res.push_back(dq[0]);
            l ++;
            r ++;
        }

        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1,3,1,2,0,5};
    vector<int>ans = sol.maxSlidingWindow(nums, 3);
    // cout << ans << endl;
    system("pause");
    return 0;
}

