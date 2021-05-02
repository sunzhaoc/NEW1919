/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-25 10:14:44
 * @LastEditTime: 2021-05-02 00:07:40
 * @FilePath: \Leetcode\Week Competition\Biweekly Contest 51\t4 copy.cpp
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


class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {        
        sort(ALL(rooms), [](const VI& x, const VI& y) {
            return x[1] < y[1];
        });
        VI roomSize;
        unordered_map<int, VI> map;
        RREP(i, SZ(rooms)) {
            if (map.find(rooms[i][1]) == map.end()) {
                roomSize.push_back(rooms[i][1]);
                if (i != SZ(rooms) - 1) {
                    map[rooms[i][1]] = map[rooms[i + 1][1]];
                    map[rooms[i][1]].PB(rooms[i][0]);
                }
                else map[rooms[i][1]].PB(rooms[i][0]);
            }
            else map[rooms[i][1]].PB(rooms[i][0]);
        }
        sort(ALL(roomSize));
        VI res;
        static  int preferred;
        static  int minSize;
        REP(i, SZ(queries)) {
            preferred = queries[i][0];
            minSize = queries[i][1];
            int l = 0, r = SZ(roomSize) - 1;
            while (l < r) {
                int mid = (r - l) / 2 + l;
                if (roomSize[mid] >= minSize) r = mid;
                else l = mid + 1;
            }

            if (roomSize[l] < minSize) {
                res.push_back(-1);
                continue;
            }
            else {
                sort(ALL(map[roomSize[l]]), [](const int& x, const int& y) {
                    return abs(x - preferred) < abs(y - preferred) || (abs(x - preferred) == abs(y- preferred) && x < y);
                });

                res.PB(map[roomSize[l]][0]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    VVI rooms = {{2,2},{1,2},{3,2}};
    VVI queries = {{3,1},{3,3},{5,2}};
    // VVI rooms = {{7,14},{11,6},{3,1},{9,4},{14,14},{17,11},{22,13},{6,25},{12,22},{21,9}};
    // VVI queries = {{21,17},{4,6},{17,25},{15,18},{17,16},{18,16},{8,17},{6,7},{9,22},{17,18}};
    // VVI queries = {{9,22},{17,18}};
    auto ans = sol.closestRoom(rooms, queries);
    // cout << ans << endl;
    REP(i, SZ(ans)) cout << ans[i] << endl;
    // REP(i, SZ(ans)) REP(j, SZ(ans[0])) cout << ans[i][j] << endl;
    system("pause");
    return 0;
}