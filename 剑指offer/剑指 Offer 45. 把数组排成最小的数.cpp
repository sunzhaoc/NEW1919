/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-05 16:47:07
 * @LastEditTime: 2021-06-24 14:59:58
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 45. 把数组排成最小的数.cpp
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
TIME:     20ms    BEAT: 16.75%    O(n) = 
MEMORY: 10.8MB    BEAT: 79.45%    O(n) = 
LAST EDIT TIME: 2021年6月24日14:58:6
Description: 空间优化了一下，时间上去了。
*/

class Solution {
public:
    string minNumber(vector<int>& nums) {
        if (nums.size() == 1) return to_string(nums[0]);

        sort(nums.begin(), nums.end(), [](const int& s1, const int& s2) {
            string add1 = to_string(s1) + to_string(s2);
            string add2 = to_string(s2) + to_string(s1);
            return add1 < add2;
        });

        string res = "";
        for (int& str: nums) res += to_string(str);
        return res;
    }
};


/*
RESULT: Accept
TIME:      8ms    BEAT: 78.15%    O(n) = 
MEMORY: 11.2MB    BEAT: 26.83%    O(n) = 
LAST EDIT TIME: 2021年6月24日14:54:54
Description: 
*/

class Solution {
public:
    string minNumber(vector<int>& nums) {
        if (nums.size() == 1) return to_string(nums[0]);

        vector<string> s;
        for (int& num: nums) s.push_back(to_string(num));

        sort(s.begin(), s.end(), [](const string& s1, const string& s2) {
            string add1 = s1 + s2;
            string add2 = s2 + s1;
            return add1 < add2;
        });

        string res = "";
        for (string& str: s) res += str;
        return res;
    }
};


/*
RESULT: Accept
TIME:     12ms    BEAT: 71.84%    O(n) = 
MEMORY: 11.6MB    BEAT: 36.69%    O(n) = 
USED TIME: 37:17
Description: Important！！！需要自定义排序规则。
*/

// class Solution {
// public:
//     string minNumber(vector<int>& nums) {
//         if (nums.size() == 1) return to_string(nums[0]);

//         vector<string> store;
//         string res = "";

//         for (int i: nums) {
//             store.push_back(to_string(i));
//         }

//         sort(store.begin(), store.end(), strCompare);
        
//         for (string i: store) {
//             res += i;
//         }

//         return res;
//     }

//     static bool strCompare(const string& s1, const string& s2) {
//         string add1 = s1 + s2;
//         string add2 = s2 + s1;
//         return add1 < add2; // 升序排列
//     }
// };
