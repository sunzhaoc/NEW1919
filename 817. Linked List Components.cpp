/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-19 12:59:59
 * @LastEditTime: 2021-04-19 13:27:48
 * @FilePath: \Leetcode\817. Linked List Components.cpp
 */
/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
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
TIME:     52ms    BEAT: 40.52%    O(n) = 
MEMORY: 20.9MB    BEAT: 37.07%    O(n) = 
USED TIME: 18:27
LAST EDIT TIME: 2021年4月19日13:27:29
Description: 
*/

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int res = 0;
        unordered_set<int> s;
        for (int x: G) s.insert(x);

        ListNode* node = head;
        while (node->next) {
            if (s.find(node->val) != s.end() && s.find(node->next->val) == s.end()) {
                res ++;
            }
            node = node->next;
        }

        if (s.find(node->val) == s.end()) return res;
        
        return res + 1;
    } 
};

// @lc code=end

