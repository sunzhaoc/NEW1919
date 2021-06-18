/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-08 13:36:37
 * @LastEditTime: 2021-04-08 15:56:41
 * @FilePath: \Leetcode\694.Number of Distinct Islands.cpp
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
TIME:     56ms    BEAT: 46.94%    O(n) = 
MEMORY: 32.8MB    BEAT: 25.51%    O(n) = 
LAST EDIT TIME: 2021年4月8日15:56:17
Description: BFS
*/

class Solution {
public:
    int numDistinctIslands(VVI& grid) {
        int m = SZ(grid), n = SZ(grid[0]);
        int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
        
        vector<vector<PII>> island;

        REP(i, m) {
            REP(j, n) {
                if (grid[i][j] == 0) continue;
                island.PB({MP(i, j)});
                stack<PII> unionLand;
                unionLand.push(MP(i, j));
                grid[i][j] = 0;
                while (unionLand.size()) {
                    int x = unionLand.top().F, y = unionLand.top().S;

                    unionLand.pop();
                    REP(k, 4) {
                        if (x + dx[k] >= 0 && x + dx[k] < m && y + dy[k] >= 0 && y + dy[k] < n && grid[x + dx[k]][y + dy[k]] == 1) {
                            unionLand.push(MP(x + dx[k], y + dy[k]));
                            island.back().PB(MP(x + dx[k], y + dy[k]));
                            grid[x + dx[k]][y + dy[k]] = 0;
                        }
                    }
                }
            }
        }

        unordered_set<string> map;
        REP(i, SZ(island)) {
            string cur = "";
            int x = island[i][0].F, y = island[i][0].S;
            REP(j, SZ(island[i])) {
                island[i][j].F -= x;
                island[i][j].S -= y;
                cur += to_string(island[i][j].F) + to_string(island[i][j].S);
            }
            map.insert(cur);
        }
        return SZ(map);
    }
};


/*
RESULT: Accept
TIME:     68ms    BEAT: 34.69%    O(n) = 
MEMORY: 27.8MB    BEAT: 63.27%    O(n) = 
LAST EDIT TIME: 2021年4月8日14:51:48
Description: 并查集 + 哈希。将岛屿最左最上坐标偏移到原点。
第200题的升级版。
*/

class Solution {
public:
    VI parent;
    int count;

    void init(VVI& grid) {
        REP(i, SZ(grid)) {
            REP(j, SZ(grid[0])) {
                if (grid[i][j] == 1) {
                    parent.PB(i * SZ(grid[0]) + j);
                    count ++;
                }
                else {
                    parent.PB(-1);
                }
            }
        }
    }

    int find(int x) {
        int son, tmp;
        son = x;
        while (x != parent[x]) {
            x = parent[x];
        }

        while (son != x) {
            tmp = parent[son];
            parent[son] = x;
            son = tmp;
        }
        return x;
    }

    void landUnion(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = SZ(grid), n = SZ(grid[0]);
        init(grid);

        REP(i, m) {
            REP(j, n) {
                if (grid[i][j] == 0) continue;
                grid[i][j] = 0;
                // Up
                if (i - 1 >= 0 && grid[i - 1][j] == 1) landUnion(i * n + j, (i - 1) * n + j);
                // Dowm
                if (i + 1 < m && grid[i + 1][j] == 1) landUnion(i * n + j, (i + 1) * n + j);
                // Left
                if (j - 1 >= 0 && grid[i][j - 1] == 1) landUnion(i * n + j, i * n + (j - 1));
                // Right                
                if (j + 1 < n && grid[i][j + 1] == 1) landUnion(i * n + j, i * n + (j + 1));
            }
        }

        REP(i, SZ(parent)) {
            if (parent[i] == -1) continue;
            parent[i] = find(parent[i]);
        }

        unordered_map<int, VI> map;

        REP(i, SZ(parent)) {
            if (parent[i] == -1) continue;
            map[parent[i]].PB(i);
        }
        
        unordered_set<string> ans;
        for (auto it = map.begin(); it != map.end(); it ++){
            int a = it->second[0] / n, b = it->second[0] % n;
            string sum = "";
            REP(i, SZ(it->second)) {
                sum += to_string(it->second[i] / n - a) + to_string(it->second[i] % n - b);
            }
            ans.insert(sum);
        }
        return SZ(ans);
    }
};


int main() {
    Solution sol;
    // VVI grid = {{1,1,1,1},{1,0,1,0},{0,0,0,0},{0,1,1,1},{1,1,0,1}};
    VVI grid = {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,1,1},{0,0,1,1}};
    auto ans = sol.numDistinctIslands(grid);
    system("pause");
    return 0;
}
s