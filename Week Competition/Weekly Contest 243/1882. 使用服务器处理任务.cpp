/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-31 10:37:39
 * @LastEditTime: 2021-05-31 10:37:39
 * @FilePath: \Leetcode\Week Competition\Weekly Contest 243\1882. 使用服务器处理任务.cpp
 */
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-25 10:14:44
 * @LastEditTime: 2021-05-31 10:29:07
 * @FilePath: \Leetcode\Week Competition\Weekly Contest 243\1882. 使用服务器处理任务.cpp
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
template<class endTime> inline void ckmin(endTime &a,endTime b){ a = min(a, b); }
template<class endTime> inline void ckmax(endTime &a,endTime b){ a = max(a, b); }
template<class endTime> inline endTime sqr(endTime x){ return x * x; }
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
template<class endTime> int CMP(endTime a[], const endTime b[], int n) { return memcmp(a, b, n * sizeof(endTime)); }
template<class endTime> void COPY(endTime a[], const endTime b[], int n) { memcpy(a, b, n * sizeof(endTime)); }
template<class endTime> void SET(endTime a[], int val, int n) { memset(a, val, n*sizeof(endTime)); }
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
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<tuple<int, int, int>, V<tuple<int, int, int>>, greater<>> freeServers;
        priority_queue<tuple<int, int, int>, V<tuple<int, int, int>>, greater<>> busyServers;
        REP(i, SZ(servers)) freeServers.push({servers[i], i, 0}); // 权重 id 0;
        VI res(SZ(tasks));
        int i = 0;
        while (1) {
            while (!busyServers.empty()) {
                auto [endTime, weight, idx] = busyServers.top();
                if (endTime > i && !freeServers.empty()) break;
                freeServers.push({weight, idx, endTime});
                busyServers.pop();
            }
            
            auto [weight, idx, endTime] = freeServers.top();
            freeServers.pop();

            res[i] = idx;
            busyServers.push({max(endTime, i) + tasks[i], weight, idx});
            if (++ i >= SZ(tasks)) break;
        }
        return res;
    }
};


int main() {
    Solution sol;
    // VI nums = {5,1,4,3,2}, tasks = {2,1,2,4,5,2,1};
    VI nums = {10,63,95,16,85,57,83,95,6,29,7};
    VI tasks = {70,31,83,15,32,67,98,65,56,48,38,90,5};
    auto ans = sol.assignTasks(nums, tasks);
    // cout << ans << endl;
    REP(i, SZ(ans)) cout << ans[i] << endl;
    // REP(i, SZ(ans)) REP(idx, SZ(ans[0])) cout << ans[i][idx] << endl;
    system("pause");
    return 0;
}