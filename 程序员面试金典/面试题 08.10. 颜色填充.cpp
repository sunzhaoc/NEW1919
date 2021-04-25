/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-08 13:34:19
 * @LastEditTime: 2021-04-08 13:34:30
 * @FilePath: \Leetcode\程序员面试金典\面试题 08.10. 颜色填充.cpp
 */

#include <bits/stdc++.h>
using namespace std;

# define POW2(X) (1 << (X))
# define CKBIT(S,X) (((S) & POW2(X)) != 0)
const double pi = acos(-1.0);
const double eps = 1e-11;
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
TIME:     12ms    BEAT: 52.76%    O(n) = 
MEMORY: 13.5MB    BEAT: 23.11%    O(n) = 
USED TIME: 13:47
LAST EDIT TIME: 2021年4月8日13:33:10
Description: BFS
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        int target = image[sr][sc];
        stack<PII> st;
        st.push(MP(sr, sc));
        int dx[4] = {0, 1, -1, 0};
        int dy[4] = {1, 0, 0, -1};
        while (st.size()) {
            int x = st.top().F, y = st.top().S;
            st.pop();
            image[x][y] = newColor;
            for (int i = 0; i < 4; i ++) {
                if (x + dx[i] < 0 || x + dx[i] == image.size() || y + dy[i] <0 || y + dy[i] == image[0].size()) continue;
                if (image[x + dx[i]][y + dy[i]] == target) st.push(MP(x + dx[i], y + dy[i]));
            }
        }
        return image;
    }
};