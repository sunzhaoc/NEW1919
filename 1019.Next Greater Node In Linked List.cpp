/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-19 10:16:13
 * @LastEditTime: 2021-04-19 10:58:05
 * @FilePath: \Leetcode\1019.Next Greater Node In Linked List.cpp
 */
/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
 */

// @lc code=start

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
# define MP(A, B) make_pair(A, B)
# define PB(X) push_back(X)
# define FOR(i, a, b) for(int i = (a); i < (b); ++i)
# define REP(i, a) for(int i = 0; i < (a); ++i)
# define ALL(A) A.begin(), A.end()
# define F first
# define S second
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
TIME:     96ms    BEAT: 82.97%    O(n) = 
MEMORY: 42.1MB    BEAT: 24.96%    O(n) = 
USED TIME: 40:18
LAST EDIT TIME: 2021年4月19日10:57:32
Description: 不会。有一点点绕。
*/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        VI res, nums;
        for (auto it = head; it != nullptr; it = it->next) nums.PB(it->val);
        reverse(ALL(nums));
        res.resize(SZ(nums));
        stack<int> q;
        REP(i, SZ(nums)) {
            while (q.size() && nums[q.top()] < nums[i]) {
                res[q.top()] = nums[i];
                q.pop();
            }
            q.push(i);            
        }
        return res;
    }
};
// @lc code=end

