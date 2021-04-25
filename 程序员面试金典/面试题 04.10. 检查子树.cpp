/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-05 20:05:57
 * @LastEditTime: 2021-04-19 16:52:00
 * @FilePath: \Leetcode\程序员面试金典\面试题 04.10. 检查子树.cpp
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


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
RESULT: Accept
TIME:     56ms    BEAT: 66.16%    O(n) = 
MEMORY: 39.2MB    BEAT: 69.22%    O(n) = 
LAST EDIT TIME: 2021年4月19日16:32:12
Description: 此为正解。
*/

class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (!t2) return true;
        if (!t1) return false;
        return isTreeEq(t1, t2) || checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }

    bool isTreeEq(TreeNode* t1, TreeNode* t2) {
        if (t1 == t2) return true;
        if (!t1 || !t2 || t1->val != t2->val) return false;
        return isTreeEq(t1->left, t2->left) && isTreeEq(t1->right, t2->right);
    }
};


/*
RESULT: Accept
TIME:     48ms    BEAT: 91.12%    O(n) = 
MEMORY: 39.2MB    BEAT: 62.48%    O(n) = 
USED TIME: 08:02
LAST EDIT TIME: 2021年4月19日16:32:12
Description: ！！！！需要说明的是，这只是针对树中没有重复元素的情况。！！！
*/

class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (!t2) return true;
        if (!t1) return false;

        if (t1->val == t2->val) return checkSubTree(t1->left, t2->left) && checkSubTree(t1->right, t2->right);
        else return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }
};