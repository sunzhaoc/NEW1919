/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2020-12-04 14:14:02
 * @LastEditTime: 2021-07-09 09:10:37
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 04. 二维数组中的查找.cpp
 */


/*
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ██姜██━██狗██ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 * 
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


/*
RESULT: Accept
TIME:     20ms    BEAT: 98.37%    O(n) = 
MEMORY: 12.7MB    BEAT: 40.48%    O(n) = 
LAST EDIT TIME: 2021年7月9日9:10:27
Description: 三刷。
*/

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = SZ(matrix);
        if (n == 0) return false;
        int m = SZ(matrix[0]), idx = 0, idy = m - 1;
        while (idx >= 0 && idx < n && idy >= 0 && idy < m) {
            if (matrix[idx][idy] == target) return true;
            if (matrix[idx][idy] > target) idy --;
            else idx ++;
        }
        return false;
    }
};


/*
RESULT: Accept
TIME:     28ms    BEAT: 64.92%    O(n) = m + n;
MEMORY: 12.7MB    BEAT: 56.05%    O(n) = 1
LAST EDIT TIME: 2021年6月18日14:56:5
Description: 二刷。
*/

// class Solution {
// public:
//     bool findNumberIn2DArray(vector<vector<int>>& array, int target) {
//         int n = array.size();
//         if (n == 0) return false;
//         int m = array[0].size();
//         int i = 0, j = m - 1;
//         while (i >= 0 && i < n && j >= 0 && j < m ){
//             if (array[i][j] == target) return true;
//             if (array[i][j] > target) j --;
//             else i ++;
//         }
//         return false;
//     }
// };


/*
RESULT: Accept
TIME:   48ms    BEAT: 93.07%    O(n) = m + n
MEMORY: 14MB    BEAT: 5.11%     O(n) = 1 
Description: 线性查找
*/

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return false;
        int min = matrix[0][0], max = matrix[matrix.size() - 1][matrix[0].size() - 1];
        if ((target > max) || (target < min))   return false;

        int row = 0, col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0)
        {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) row ++;
            else col --;                         
        }
        return false;
    }
};


int main(){
    Solution sol;
    bool ans = sol.findNumberIn2DArray({{}}, 20);
    cout << ans << endl;
    system("pause");
    return 0;
}