/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-09 19:39:23
 * @LastEditTime: 2021-04-09 20:01:34
 * @FilePath: \Leetcode\1474.Delete N Nodes After M Nodes of a Linked List.cpp
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
using VS = vector<string>;
using VVS = vector<VS>;


/*
RESULT: Accept
TIME:     36ms    BEAT: 70.79%    O(n) = 
MEMORY: 15.3MB    BEAT: 64.04%    O(n) = 
USED TIME: 16:54
LAST EDIT TIME: 2021年4月9日19:58:44
Description: 写得丑，懒得改了。
*/

class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        auto l = dummy, r = dummy;
        bool flag = false;
        while (r != nullptr) {
            REP(i, m) {
                l = l->next;
                if (l == nullptr) {
                    break;
                }
            }
            if (l == nullptr) {
                break;
            }
            REP(i, m + n) {
                if (r->next == nullptr) {
                    flag = true;
                    break;
                }
                r = r->next;
            }
            l->next = r->next;
            r = l;
            if (flag) break;
        }
        return head;
    }
};