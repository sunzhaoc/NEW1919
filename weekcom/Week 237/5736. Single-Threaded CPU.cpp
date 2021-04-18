/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-17 22:13:10
 * @LastEditTime: 2021-04-18 13:16:49
 * @FilePath: \Leetcode\weekcom\Week 237\5736. Single-Threaded CPU.cpp
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
    vector<int> getOrder(vector<vector<int>>& tasks) {
        set<LL> startTime;
        VI res;
        int id = 0;
        LL curTime = -1;

        REP(i, SZ(tasks)) tasks[i].PB(i);
        sort(ALL(tasks));
        
        REP(i, SZ(tasks)) startTime.insert(tasks[i][0]);

        struct cmp {
            bool operator() (const PLL& x, const PLL& y) {
                return x.S > y.S || (x.S == y.S && x.F > y.F);
            }
        };
        
        priority_queue<PLL, VPLL, cmp> q;

        for (auto it = startTime.begin(); it != startTime.end(); it ++) {
            if (*it <= curTime) continue;
            curTime = *it;
            FOR(i, id, SZ(tasks)) {
                if (tasks[i][0] == curTime) {
                    q.push(MP(tasks[i][2], tasks[i][1])); // id, LastTime
                    id = i + 1;
                }
                else {
                    id = i;
                    break;
                }
            }

            while (q.size()) {
                res.PB(q.top().F);
                curTime += q.top().S;
                q.pop();
                
                FOR(i, id, SZ(tasks)) {
                    if (tasks[i][0] <= curTime) {
                        q.push(MP(tasks[i][2], tasks[i][1])); // id, LastTime
                        id = i + 1;
                    }
                    else {
                        id = i;
                        break;
                    }
                }
            }
        }
        
        while (q.size()) {
            res.PB(q.top().F);
            q.pop();
        }
        return res;
    }
};


int main() {
    Solution sol;
    // VVI nums = {{1,2},{2,4},{3,2},{4,1}};
    // VVI nums = {{19,13},{16,9},{21,10},{32,25},{37,4},{49,24},{2,15},{38,41},{37,34},{33,6},{45,4},{18,18},{46,39},{12,24}};
    VVI nums = {{7,10},{7,12},{7,5},{7,4},{7,2}};
    auto ans = sol.getOrder(nums);
    REP(i, SZ(ans)) cout << ans[i] << endl;
    system("pause");
    return 0;
}