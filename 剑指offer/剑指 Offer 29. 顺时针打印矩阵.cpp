/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2020-12-04 15:04:14
 * @LastEditTime: 2021-07-10 14:39:50
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 29. 顺时针打印矩阵.cpp
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
TIME:     8ms    BEAT: 94.51%    O(n) = 
MEMORY: 9.7MB    BEAT: 47.36%    O(n) = 
LAST EDIT TIME: 2021年7月10日14:39:39
Description: 
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (SZ(matrix) == 0) return {};
        int u = 0, d = SZ(matrix) - 1, l = 0, r = SZ(matrix[0]) - 1;
        VI res;
        while (1) {
            FOR(i, l, r + 1) res.PB(matrix[u][i]);
            u ++;
            if (u > d) break;
            FOR(i, u, d + 1) res.PB(matrix[i][r]);
            r --;
            if (l > r) break;
            for (int i = r; i >= l; i --) res.PB(matrix[d][i]);
            d --;
            if (u > d) break;
            for (int i = d; i >= u; i --) res.PB(matrix[i][l]);
            l ++;
            if (l > r) break;
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:    16ms    BEAT: 26.17%    O(n) = 
MEMORY: 9.7MB    BEAT: 50.97%    O(n) = 
LAST EDIT TIME: 2021年6月22日16:5:4
Description: 
*/

// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         if (matrix.size() == 0) return {};
//         int u = 0, d = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;
//         vector<int> res;
//         while (1) {
//             for (int i = l; i <= r; i ++) res.push_back(matrix[u][i]);
//             u ++;
//             if (u > d) break;
//             for (int i = u; i <= d; i ++) res.push_back(matrix[i][r]);
//             r --;
//             if (l > r) break;
//             for (int i = r; i >= l; i --) res.push_back(matrix[d][i]);
//             d --;
//             if (u > d) break;
//             for (int i = d; i >= u; i --) res.push_back(matrix[i][l]);
//             l ++;
//             if (l > r) break;
//         }
//         return res;
//     }
// };


/*
RESULT: Accept
TIME:     28ms    BEAT: 24.45%    O(n) = mn
MEMORY: 10.5MB    BEAT:  5.01%    O(n) = 1?
Description: 使用四条边来定义边界，当 left > right 或 up > down 时，退出。
*/

// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>> matrix) {
//         if (matrix.size() == 0 || matrix[0].size() == 0) return {};
//         int up = 0, down = (int)matrix.size() - 1, left = 0, right = (int)matrix[0].size() - 1;
//         vector<int> ans;
        
//         while (1)
//         {
//             for (int i = left; i <= right; i ++)    ans.push_back(matrix[up][i]);
//             up ++;
//             if (up > down) break;

//             for (int i = up; i <= down; i ++)   ans.push_back(matrix[i][right]);
//             right --;
//             if (left > right) break;

//             for (int i = right; i >= left; i --)    ans.push_back(matrix[down][i]);
//             down --;
//             if (up > down) break;
            
//             for (int i = down; i >= up; i --)   ans.push_back(matrix[i][left]);
//             left ++;
//             if (left > right) break;
//         }
//         return ans;
//     }
// };


/*
RESULT: Accept
TIME:     20ms    BEAT: 91.14%    O(n) = mn
MEMORY: 10.5MB    BEAT:  5.01%    O(n) = 1?
Description: 使用四个角的点的坐标来定义边界,用计数的方法来判断退出条件。
*/

// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>> matrix) {
//         if (matrix.size() == 0 || matrix[0].size() == 0) return {};
//         vector<int> up_left = {0, 0}, up_right = {0, (int)matrix[0].size() - 1};
//         vector<int> down_left = {(int)matrix.size() - 1, 0}, down_right = {(int)matrix.size() - 1, (int)matrix[0].size() - 1};
//         int sum = matrix.size() * matrix[0].size(), num = 0;
//         vector<int> ans;
        
//         while (1)
//         {
//             for (int i = up_left[1]; i <= up_right[1]; i++){
//                 ans.push_back(matrix[up_left[0]][i]);
//                 num ++;
//             }
//             up_left[0]++;   
//             up_right[0]++;
//             if (num >= sum) break;

//             for (int i = up_right[0]; i <= down_right[0]; i++){
//                 ans.push_back(matrix[i][up_right[1]]);
//                 num ++;
//             }
//             up_right[1]--;
//             down_right[1]--;
//             if (num >= sum) break;

//             for (int i = down_right[1]; i >= down_left[1]; i--){
//                 ans.push_back(matrix[down_right[0]][i]);
//                 num ++;
//             }
//             down_right[0]--;
//             down_left[0]--;
//             if (num >= sum) break;

//             for (int i = down_left[0]; i >= up_left[0]; i--){
//                 ans.push_back(matrix[i][down_left[1]]);
//                 num ++;
//             }
//             down_left[1]++;
//             up_left[1]++;
//             if (num >= sum) break;
//         }
//         return ans;
//     }
// };


int main(){
    Solution sol;
    vector<int> ans = sol.spiralOrder({{1,2,3},{4,5,6},{7,8,9}});
    // vector<int> ans = sol.spiralOrder({{1,2,3,4},{5,6,7,8},{9,10,11,12}});
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}