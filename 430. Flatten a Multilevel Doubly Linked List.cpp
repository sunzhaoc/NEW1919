/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-19 09:45:02
 * @LastEditTime: 2021-04-19 10:14:40
 * @FilePath: \Leetcode\430. Flatten a Multilevel Doubly Linked List.cpp
 */
/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
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
TIME:     4ms    BEAT: 90.69%    O(n) = 
MEMORY: 7.2MB    BEAT: 47.18%    O(n) = 
USED TIME: 28:29
LAST EDIT TIME: 2021年4月19日10:14:22
Description: 
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        while (cur) {
            if (!cur->child) {
                cur = cur->next;
                continue;
            }
            
            Node* tmp = cur->child;
            while (tmp->next) tmp = tmp->next;
            Node* next_node = cur->next;
            
            if (!next_node) {
                cur->child->prev = cur;
                cur->next = cur->child;
                cur->child = nullptr;
                cur = cur->next;
                continue;
            }
            tmp->next = next_node;
            next_node->prev = tmp;
            

            cur->child->prev = cur;
            cur->next = cur->child;

            cur->child = nullptr;
            
            cur = cur->next;
        }
        return head;
    }
};
// @lc code=end

