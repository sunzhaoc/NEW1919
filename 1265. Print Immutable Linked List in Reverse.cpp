/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-19 21:37:48
 * @LastEditTime: 2021-04-19 21:42:06
 * @FilePath: \Leetcode\1265. Print Immutable Linked List in Reverse.cpp
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
# define MP(A, B) make_pair(A, B)
# define PB(X) push_back(X)
# define FOR(i, a, b) for(int i = (a); i < (b); ++i)
# define REP(i, a) for(int i = 0; i < (a); ++i)
# define ALL(A) A.begin(), A.end()
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


// This is the ImmutableListNode's API interface.
// You should not implement it, or speculate about its implementation.
class ImmutableListNode {
public:
   void printValue(); // print the value of the node.
   ImmutableListNode* getNext(); // return the next node.
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 7.5MB    BEAT:  78.33%    O(n) = 
USED TIME: 01:49
LAST EDIT TIME: 2021年4月19日21:41:16
Description: 真是无聊的题。。。搞那么NB。。。
*/

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (!head) return;
        printLinkedListInReverse(head->getNext());
        head->printValue();
    }
};