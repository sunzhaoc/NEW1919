/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-07 19:35:55
 * @LastEditTime: 2021-04-07 19:53:59
 * @FilePath: \Leetcode\程序员面试金典\面试题 08.04. 幂集.cpp
 */

#include <bits/stdc++.h>
using namespace std;

# define POW2(X) (1 << (X))
# define CKBIT(S,X) (((S) & POW2(X)) != 0)
const double pi = acos(-1.0);
const double eps = 1e-11;
template<class T> inline void ckmin(T &a,T b){ a = min(a, b); }
template<class T> inline void ckmax(T &a,T b){ a = max(a, b); }
template<class T> inline T sqr(T x){ return x * x; }
# define SZ(A) ((int)A.size())
# define LENGTH(A) ((int)A.length())
# define MP(A, B) make_pair(A, B)
# define PB(X) push_back(X)
# define FOR(i, a, b) for(int i = (a); i < (b); ++i)
# define REP(i, a) for(int i = 0; i < (a); ++i)
# define ALL(A) A.begin(), A.end()
# define F first
# define S second
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
using VS = vector<string>;
using VVS = vector<VS>;

/*
RESULT: Accept
TIME:   0ms    BEAT: 100.00%    O(n) = 
MEMORY: 7MB    BEAT:  54.97%    O(n) = 
USED TIME: 14:15
LAST EDIT TIME: 2021年4月7日19:53:5
Description: 求集合的子集。
*/

class Solution {
public:
    VVI ans;
    int N;
    vector<vector<int>> subsets(vector<int>& nums) {
        N = nums.size();
        VI block;
        backTrack(nums, block, 0);
        return ans;
    }

    void backTrack(VI& nums, VI& used, int id) {
        if (id > N) return;
        ans.PB(used);
        FOR (i, id, N) {
            used.PB(nums[i]);
            backTrack(nums, used, i + 1);
            used.pop_back();
        }
    }
};

int main() {
    Solution sol;
    VI nums = {1, 2, 3};
    VVI ans = sol.subsets(nums);
    return 0;
}