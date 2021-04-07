/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-07 15:14:44
 * @LastEditTime: 2021-04-07 15:49:22
 * @FilePath: \Leetcode\89.Gray Code.cpp
 */
/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

#define POW2(X) (1<<(X))
#define CKBIT(S,X) (((S)&POW2(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
template<class T> inline T sqr(T x){ return x*x; }
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
template<class T> int CMP(T a[],const T b[],int n) { return memcmp(a,b,n*sizeof(T)); }
template<class T> void COPY(T a[],const T b[],int n) { memcpy(a,b,n*sizeof(T)); }
template<class T> void SET(T a[],int val,int n) { memset(a,val,n*sizeof(T)); }
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;
using VVI=vector<VI>;
using VS=vector<string>;

/*
RESULT: Accept
TIME:     12ms    BEAT: 46.54%    O(n) = 
MEMORY: 12.3MB    BEAT: 15.34%    O(n) = 
USED TIME: 32:16
LAST EDIT TIME: 2021年4月7日15:47:55
Description: 找规律。跟回溯没有半毛钱关系。
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1) return {0, 1};
        VI ans = {0, 1 ,3, 2};
        for (int i = 2; i < n; i ++) {
            VI newans = ans;
            reverse(ALL(newans));
            REP (j, SIZE(newans)) {
                newans[j] += 1 << i;
            }
            ans.insert(ans.end(), ALL(newans));
        }
        return ans;
    }
};
// @lc code=end

