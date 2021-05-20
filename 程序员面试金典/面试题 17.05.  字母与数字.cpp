/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-18 16:01:32
 * @LastEditTime: 2021-05-18 19:24:48
 * @FilePath: \Leetcode\程序员面试金典\面试题 17.05.  字母与数字.cpp
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
TIME:    208ms    BEAT: 11.90%    O(n) = 
MEMORY: 97.2MB    BEAT:  5.15%    O(n) = 
USED TIME: 边界条件无数。草。
LAST EDIT TIME: 2021年5月18日19:6:42
Description: 
*/

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        VI arr;
        REP(i, SZ(array)) arr.PB(((array[i] >= "a" && array[i] <= "z") || (array[i] >= "A" && array[i] <= "Z")) ? 1 : -1);
        FOR(i, 1, SZ(arr)) arr[i] += arr[i - 1];
        unordered_map<int, pair<int, int>> m;
        m[0] = {-1, -1};
        REP(i, SZ(arr)) {
            if (m.find(arr[i]) == m.end()) {
                m[arr[i]] = MP(i, i);
            }
            else m[arr[i]].second = i;
        }

        int len = INT_MIN;
        int idx = 0;

        for (auto it = m.begin(); it != m.end(); it ++) {
            if (it->second.second == it->second.first) continue;
            if (it->second.second - it->second.first > len) {
                len = it->second.second - it->second.first;
                idx = it->second.first;
            }
            else if (it->second.second - it->second.first == len && it->second.first < idx) idx = it->second.first;
        }
        if (len < 0) return {};
        VS res;
        FOR(i, idx + 1, idx + len + 1) res.PB(array[i]);
        return res;
    }
};


int main() {
    Solution sol;
    // VS array = {"A", "1"};
    // VS array = {"A", "A"};
    VS array = {"42","10","O","t","y","p","g","B","96","H","5","v","P","52","25","96","b","L","Y","z","d","52","3","v","71","J","A","0","v","51","E","k","H","96","21","W","59","I","V","s","59","w","X","33","29","H","32","51","f","i","58","56","66","90","F","10","93","53","85","28","78","d","67","81","T","K","S","l","L","Z","j","5","R","b","44","R","h","B","30","63","z","75","60","m","61","a","5","S","Z","D","2","A","W","k","84","44","96","96","y","M"};
    // VS array = {"A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"};
    auto res = sol.findLongestSubarray(array);
    REP(i, SZ(res)) cout << res[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}