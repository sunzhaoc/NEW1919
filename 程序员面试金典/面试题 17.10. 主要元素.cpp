/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-15 19:37:07
 * @LastEditTime: 2021-04-15 19:38:12
 * @FilePath: \Leetcode\程序员面试金典\面试题 17.10. 主要元素.cpp
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


/*
RESULT: Accept
TIME:     16ms    BEAT: 91.23%    O(n) = 
MEMORY: 18.4MB    BEAT: 29.09%    O(n) = 
USED TIME: 17:27
LAST EDIT TIME: 2021年4月15日19:37:16
Description: 摩尔投票。需要注意的是，最后，如果 count > 0 也得检查是不是真的超过了数组长度的二分之一。
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int people = -1, ticket = 0;
        for (int i: nums) {
            if (ticket == 0) {
                ticket = 1;
                people = i;
            }
            else if (people == i) {
                ticket ++;
            }
            else {
                ticket --;
            }
        }
        
        if (ticket > 0) {
            int n = 0;
            for (int i: nums) if (i == people) n ++;
            if (n > SZ(nums) / 2) return people;
        }
        return -1;
    }
};