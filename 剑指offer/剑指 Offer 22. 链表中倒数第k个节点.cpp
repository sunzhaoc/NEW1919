/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-30 16:11:53
 * @LastEditTime: 2021-06-21 19:48:25
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 22. 链表中倒数第k个节点.cpp
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
TIME:      0ms    BEAT: 100.00%    O(n) = 
MEMORY: 10.2MB    BEAT:  74.57%    O(n) = 
LAST EDIT TIME: 2021年6月21日19:47:54 
Description: 快慢指针。
*/

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* l = head, * r = head;
        for (int i = 0; i < k; i ++) r = r->next;
        while (r) { 
            r = r->next;
            l = l->next;
        }
        return l;
    }
};


/*
RESULT: Accept
TIME:      4ms    BEAT: 76.49%    O(n) = 
MEMORY: 10.3MB    BEAT: 59.70%    O(n) = 
LAST EDIT TIME: 2021年6月21日19:42:25
Description: 先遍历，计算第几个。
*/

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int cnt = 0;
        for (auto it = head; it; it = it->next) cnt ++;
        cnt = cnt - k;
        ListNode* res = head;
        while (cnt --) res = res->next;
        return res;
    }
};



/*
RESULT: Accept
TIME:      0ms    BEAT: 100.00%    O(n) = n
MEMORY: 10.8MB    BEAT:  26.93%    O(n) = 1
Description: 双指针。
*/

// class Solution {
// public:
//     ListNode* getKthFromEnd(ListNode* head, int k) {
//         ListNode* point_left = head;
//         ListNode* point_right = head;

//         for (int i = 0; i < k; i ++) {
//             point_right = point_right->next;
//         }
        
//         while (point_right != nullptr) {
//             point_left = point_left->next;
//             point_right = point_right->next;
//         }
//         return point_left;
//     }
// };