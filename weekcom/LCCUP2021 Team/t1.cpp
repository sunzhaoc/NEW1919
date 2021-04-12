/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-09 21:33:50
 * @LastEditTime: 2021-04-10 17:32:26
 * @FilePath: \Leetcode\weekcom\LCCUP2021 Team\t1.cpp
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
using VS = vector<string>;
using VVS = vector<VS>;



class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int cnt = 0;
        int n = SZ(bucket);
        REP(i, n) {
            if (bucket[i] == 0 && vat[i] != 0) {
                bucket[i] ++;
                cnt ++;
            }
        }

        VPII maxHeap;
        REP (i, n) {
            int tmpTime = (vat[i] + bucket[i] - 1) / bucket[i];
            // maxHeap.push(MP(tmpTime, i));
            maxHeap.PB(MP(tmpTime, i));
        }

        sort(ALL(maxHeap), [](const PII& x, const PII& y) {
            return x.F > y.F; 
        });

        while (1) {
            int maxTimes = maxHeap[0].F;
            int maxTimesNum = 0;
            
            if (maxTimes == 0) return cnt;
            if (maxTimes == 1) return cnt + 1;
            // 给次数最多的加水。
            REP(i, SZ(maxHeap)) {
                if (maxHeap[i].F == maxTimes) maxTimesNum ++;
                else break;
            }

            int newmaxTimes = INT_MIN;
            REP(i, maxTimesNum) {
                newmaxTimes = max(newmaxTimes, (vat[maxHeap[i].S] + bucket[maxHeap[i].S] + 1 - 1) / (bucket[maxHeap[i].S] + 1));
            }

            // 给每个加水
            int new2maxTime = INT_MIN;
            REP(i, n) {
                if (vat[i] - bucket[i] <= 0) new2maxTime = max(new2maxTime, 1);
                else new2maxTime = max(new2maxTime, (vat[i] - bucket[i] + bucket[i] - 1) / bucket[i]);
            }
            
            if (newmaxTimes + maxTimesNum < new2maxTime + 1) {
                if (newmaxTimes + maxTimesNum < maxTimes) {
                    cnt += maxTimesNum;
                    REP(i, maxTimesNum) {
                        maxHeap[i].F = (vat[maxHeap[i].S] + bucket[maxHeap[i].S] + 1 - 1) / (bucket[maxHeap[i].S] + 1);
                        bucket[maxHeap[i].S] += 1;
                    }
                    sort(ALL(maxHeap), [](const PII& x, const PII& y) {
                        return x.F > y.F; 
                    });
                }
                else return cnt + maxTimes;
            }
            else {
                REP(i, SZ(maxHeap)) {
                    maxHeap[i].F --;
                }
                REP(i, SZ(vat)) {
                    if (vat[i] - bucket[i] >= 0) vat[i] -= bucket[i]; 
                    else vat[i] = 0;
                }
                cnt ++;
            }
            int x = 0;
        }
        return cnt;
    }
};


int main () {
    Solution sol;
    // VI bucket = {1, 3};
    // VI vat = {6, 8};
    // VI bucket = {1, 1};
    // VI vat = {1, 1};
    // VI bucket = {9,0,1};
    // VI vat = {0,2,2};
    VI bucket = {1,1,1};
    VI vat = {1000,2000,3000};
    // VI bucket = {1,2,3};
    // VI vat = {1000,0,3000};
    auto ans = sol.storeWater(bucket, vat);
    cout << ans << endl;
    system("pause");
    return 0;
}