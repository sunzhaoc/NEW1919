/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-16 10:17:56
 * @LastEditTime: 2021-04-16 10:31:47
 * @FilePath: \Leetcode\622.Design Circular Queue.cpp
 */
/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
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
using VDD = vector<VD>;
using VS = vector<string>;
using VVS = vector<VS>;


/*
RESULT: Accept
TIME:     44ms    BEAT:  7.35%    O(n) = 
MEMORY: 16.4MB    BEAT: 26.46%    O(n) = 
LAST EDIT TIME: 2021年4月16日10:31:28
Description: 直接CV。
*/

class MyCircularQueue {
private:
    vector<int> vec;
    int head, tail;
    int max_size;
    int cur_size;
    
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k):max_size(k), head(0), tail(0), vec(vector<int>(k)), cur_size(0) {

    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(this->isFull())
            return false;
        if(this->cur_size != 0) // 考虑如果 这时是空队列， 那么需要再原地添加（tail不移动）， 而不需要后移位置
            this->tail = (++this->tail) % this->max_size;
        this->vec[this->tail] = value;
        this->cur_size++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(this->isEmpty())
            return false;
        this->cur_size--;
        if(this->cur_size != 0) // 如果dequeue之后为空，那么head将不移动， 否则后移一位
            this->head = (++this->head) % this->max_size;
        
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(this->isEmpty())
            return -1;
        return this->vec[this->head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(this->isEmpty())
            return -1;
        return this->vec[this->tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(this->cur_size == 0)
            return true;
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(this->cur_size == this->max_size){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

