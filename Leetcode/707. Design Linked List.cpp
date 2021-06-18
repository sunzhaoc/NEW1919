/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-09 20:02:13
 * @LastEditTime: 2021-04-09 21:13:56
 * @FilePath: \Leetcode\707.Design Linked List.cpp
 */
/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start

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
TIME:     56ms    BEAT: 34.74%    O(n) = 
MEMORY: 19.3MB    BEAT: 16.41%    O(n) = 
USED TIME: 01:07:01
LAST EDIT TIME: 2021年4月9日21:13:11
Description: 我可真是个傻狗。这么Easy的题，Debug了一个小时。
*/

class MyLinkedList {
public:
    struct LinkNode
    {
        int val;
        LinkNode* next;
        LinkNode* prev;
        LinkNode(int x): val(x), next(nullptr), prev(nullptr) {}
    };
    
    int N = -1;
    LinkNode* dummy;

    /** Initialize your data structure here. */
    MyLinkedList() {
        dummy = new LinkNode(-1);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index > N || index < 0) return -1;
        LinkNode* tmpNode = dummy->next;
        REP(i, index) {
            tmpNode = tmpNode->next;
        }
        return tmpNode->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkNode* newNode = new LinkNode(val);
        if (N == -1) {
            dummy->next = newNode;
            newNode->prev = dummy;
        }
        else {
            auto tmpNode = dummy->next;
            dummy->next = newNode;
            newNode->prev = dummy;
            newNode->next = tmpNode;
            tmpNode->prev = newNode;
        }
        N ++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkNode* newNode = new LinkNode(val);
        LinkNode* tmpNode = dummy;
        while (tmpNode->next != nullptr) {
            tmpNode = tmpNode->next;
        }
        tmpNode->next = newNode;
        newNode->prev = tmpNode;
        newNode->next = nullptr;
        N ++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        LinkNode* newNode = new LinkNode(val);
        if (index <= 0) {
            if (N == -1) {
                dummy->next = newNode;
                newNode->prev = dummy;
            }
            else {
                auto tmpNode = dummy->next;
                dummy->next = newNode;
                newNode->prev = dummy;
                newNode->next = tmpNode;
                tmpNode->prev = newNode;
            }
        }
        else if (index == N + 1) {
            LinkNode* tmpNode = dummy;
            while (tmpNode->next != nullptr) {
                tmpNode = tmpNode->next;
            }
            tmpNode->next = newNode;
            newNode->prev = tmpNode;
            newNode->next = nullptr;
        }
        else if (index > N + 1) return;
        else {
            LinkNode* tmpNode = dummy;
            REP(i, index) {
                tmpNode = tmpNode->next;
            }
            LinkNode* nextNode = tmpNode->next;
            tmpNode->next = newNode;
            newNode->prev = tmpNode;
            newNode->next = nextNode;
            nextNode->prev = newNode;
        }
        N ++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index > N) return;
        LinkNode* curNode = dummy;
        REP(i, index) curNode = curNode->next;
        LinkNode* nextNode = curNode->next->next;
        
        if (nextNode == nullptr) curNode->next = nullptr;
        else {
            curNode->next = nextNode;
            nextNode->prev = curNode;
        }
        N --;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

