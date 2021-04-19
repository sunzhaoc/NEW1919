/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-19 15:02:13
 * @LastEditTime: 2021-04-19 15:24:08
 * @FilePath: \Leetcode\708. Insert into a Sorted Circular Linked List.cpp
 */

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
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
TIME:   12ms    BEAT: 35.90%    O(n) = 
MEMORY:  8MB    BEAT: 51.28%    O(n) = 
USED TIME: 02:20
LAST EDIT TIME: 2021年4月19日15:23:58
Description: 
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* res = new Node(insertVal);
            res->next = res;
            return res;
        }
        
        Node* cur = head;
        while (cur->next != head) {
            // 非最值
            if (cur->val <= insertVal && insertVal <= cur->next->val) {
                break;
            }
            // 最大值
            else if (cur->val <= insertVal && insertVal > cur->next->val && cur->val > cur->next->val) {
                break;
            }
            // 最小值
            else if (cur->val > insertVal && cur->next->val >= insertVal && cur->val > cur->next->val) {
                break;
            }
            cur = cur->next;
        }
        
        Node* inserted = new Node(insertVal);
        inserted->next = cur->next;
        cur->next = inserted;
        return head;
    }
};