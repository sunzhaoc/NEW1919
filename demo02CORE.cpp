/*
 * @Description: 
 * 
 * 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-14 19:49:48
 * @LastEditTime: 2021-04-14 20:30:49
 * @FilePath: \Leetcode\demo02CORE.cpp
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




class Solution {
public:
    unordered_set<int> res;
    unordered_set<int> aebres;
    
    VI function(VI& speed) {
        int n = SZ(speed), i = 0, tmp = 60;
        while (tmp < n) {
            tmp *= i;
            res.insert(tmp);
            i ++;
        }
        
        i = 4;
        while(i < n) {
            if (speed[i - 4] - speed[i - 3] >= 9 && speed[i - 3] - speed[i - 2] >= 9 && speed[i - 2] - speed[i - 1] >= 9 && speed[i - 1] - speed[i] >= 9) {
                int k = i;
                while (speed[k - 1] - speed[k] >= 9) k ++;
                k --;
                
                FOR(j, max(0, i - 8), min(n, k + 4 + 1)) {
                    aebres.insert(j);
                }
                FOR(j, i - 4, min(n, k + 1)) {
                    if (res.find(j) != res.end()) res.erase(j);
                }
                i = k;
            }
            else i ++;
        }
        
        VI ans;
        for (auto it = res.begin(); it != res.end(); it ++) ans.PB(*it);
        for (auto it = aebres.begin(); it != aebres.end(); it ++) ans.PB(*it);
        sort(ALL(ans));
        return ans;
    }
};

int main() {
    Solution sol;
    VI nums = {2,3,1,1};
    int n = 4;
    auto it = sol.function(n, nums);
    cout << it << endl;
    system("pause");
    return 0;
}


