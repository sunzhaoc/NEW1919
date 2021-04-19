/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-19 13:56:16
 * @LastEditTime: 2021-04-19 14:27:41
 * @FilePath: \Leetcode\1634. Add Two Polynomials Represented as Linked Lists.cpp
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


// Definition for polynomial singly-linked list.
struct PolyNode {
    int coefficient, power;
    PolyNode *next;
    PolyNode(): coefficient(0), power(0), next(nullptr) {};
    PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
    PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
};


/*
RESULT: Accept
TIME:    108ms    BEAT: 85.11%    O(n) = 
MEMORY: 37.8MB    BEAT: 91.49%    O(n) = 
USED TIME: 23:12
LAST EDIT TIME: 2021年4月19日14:27:27
Description: 
*/

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* p1 = poly1, * p2 = poly2;
        PolyNode* dummy = new PolyNode(-1, -1);
        dummy->next = p1;
        PolyNode* pre = dummy;

        while (p1 || p2) {
            if (p1 && p2) {
                // 指数相等
                if (p1->power == p2->power) {
                    p1->coefficient += p2->coefficient;
                    // 系数不为0
                    if (p1->coefficient != 0) {
                        pre = p1;
                        p1 = p1->next;
                        p2 = p2->next;
                    }
                    // 系数为0
                    else {
                        p1 = p1->next;
                        p2 = p2->next;
                        pre->next = p1;
                    }
                }
                else if (p1->power > p2->power) {
                    pre = p1;
                    p1 = p1->next;
                }
                else if (p1->power < p2->power) {
                    pre->next = p2;
                    auto tmp = p2->next;
                    p2->next = p1;
                    p2 = tmp;
                    pre = pre->next;
                }
            }
            else if (p1) {
                break;
            }
            else {
                pre->next = p2;
                break;
            }
        }
        return dummy->next;
    }
};
