/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2020-12-07 14:42:50
 * @LastEditTime: 2021-07-09 09:26:19
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 06. 从尾到头打印链表.cpp
 */


// Definition for singly-linked list.
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
TIME:     4ms    BEAT: 87.84%    O(n) = n
MEMORY: 8.5MB    BEAT: 52.59%    O(n) = n
LAST EDIT TIME: 2021年7月9日9:23:40
Description: 三刷。
*/

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        VI res;
        for (ListNode* it = head; it; it = it->next) res.emplace_back(it->val);
        reverse(ALL(res));
        return res;
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 87.72%    O(n) = 
MEMORY: 8.4MB    BEAT: 78.19%    O(n) = 
LAST EDIT TIME: 2021年6月18日15:10:56
Description: 二刷。
*/

// class Solution {
// public:
//     vector<int> reversePrint(ListNode* head) {
//         vector<int> res;
//         for (auto it = head; it; it = it->next) res.push_back(it->val);
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };


/*
RESULT: Accept
TIME:     8ms    BEAT: 71.58%    O(n) = n
MEMORY: 8.8MB    BEAT: 59.85%    O(n) = n
Description: 改变链表结构法。
*/

// class Solution {
// public:
//     vector<int> ans;
//     vector<int> reversePrint(ListNode* head) {
//         ListNode *pre = nullptr;
//         ListNode *next = head;
//         ListNode *cur = head;

//         while (cur){
//             next = cur->next;   //保存当前结点的下一个节点
//             cur->next = pre;    //当前结点指向前一个节点，反向改变指针
//             pre = cur;  //更新前一个节点
//             cur = next; //更新当前结点
//         }

//         while (pre){
//             ans.push_back(pre->val);
//             pre = pre->next;
//         }

//         return ans;      
//     }
// };


/*
RESULT: Accept
TIME:      20ms    BEAT: 10.68%    O(n) = n
MEMORY:   9.2MB    BEAT: 16.55%    O(n) = n
Description: 堆栈法，因为输出为逆序，可以利用堆栈的性质。
*/

// class Solution {
// public:
//     vector<int> ans;
//     vector<int> reversePrint(ListNode* head) {
//         stack<int> s;
        
//         // 入栈
//         while (head){
//             s.push(head->val);
//             head = head->next;
//         }

//         // 出栈
//         while (!s.empty())
//         {
//             ans.push_back(s.top());
//             s.pop();
//         }
//         return ans;                
//     }
// };


/*
RESULT: Accept
TIME:      56ms    BEAT: 7.40%    O(n) = n
MEMORY: 248.7MB    BEAT: 5.01%    O(n) = n
Description: 递归解法。链表非常长时可能导致函数调用栈溢出。
*/

// class Solution {
// public:
//     vector<int> ans;

//     vector<int> reversePrint(ListNode* head) {
//         if (head == nullptr)    return ans;
//         reversePrint(head->next);
//         ans.push_back(head->val);
//         return ans;
//     }
// };


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = n
MEMORY: 8.7MB    BEAT:  73.12%    O(n) = 1
Description: 利用algorithm中的reverse函数进行反转。
*/

// class Solution {
// public:
//     vector<int> reversePrint(ListNode* head) {
//         vector<int> ans;
//         while (head)
//         {   
//             ans.push_back(head->val);
//             head = head->next;
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };