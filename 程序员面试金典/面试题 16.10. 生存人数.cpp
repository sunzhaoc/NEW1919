/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-19 20:20:39
 * @LastEditTime: 2021-04-19 20:49:26
 * @FilePath: \Leetcode\程序员面试金典\面试题 16.10. 生存人数.cpp
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
TIME:   36ms    BEAT: 92.00%    O(n) = 
MEMORY: 26MB    BEAT: 66.67%    O(n) = 
LAST EDIT TIME: 2021年4月19日20:49:24
Description: 差分运算。
*/

class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        int n = SZ(birth);
        VI year(102, 0);
        REP(i, n) {
            int x = birth[i], y = death[i];
            year[x - 1900] += 1;
            year[y - 1900 + 1] -= 1;
        }
        int maxPeople = -1;
        int maxPeopleYear = -1;
        int curPeople = 0;
        REP(i, 102) {
            curPeople += year[i];
            if (curPeople > maxPeople) {
                maxPeople = curPeople;
                maxPeopleYear = i;
            }
        }
        return maxPeopleYear+1900;
    }
};


/*
RESULT: Accept
TIME:     40ms    BEAT: 82.00%    O(n) = n
MEMORY: 26.1MB    BEAT: 24.67%    O(n) = 1
LAST EDIT TIME: 2021年4月19日20:40:51
Description: 没必要用哈希表。vector就行。
*/

class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        VI birth_year(102);
        VI death_year(102);

        for (int year: birth) birth_year[year - 1899] ++;
        for (int year: death) death_year[year - 1899] ++;

        int people = 0;
        int maxPeople = -1;
        int maxPeopleYear = -1;
        FOR(year, 1900, 2001) {
            people += birth_year[year - 1899] - death_year[year - 1899 - 1];
            if (people > maxPeople) {
                maxPeople = people;
                maxPeopleYear = year;
            }
        }
        return maxPeopleYear;
    }
};


/*
RESULT: Accept
TIME:     48ms    BEAT: 51.11%    O(n) = 
MEMORY: 27.1MB    BEAT:  5.56%    O(n) = 
USED TIME: 16:25
LAST EDIT TIME: 2021年4月19日20:37:58
Description: 
*/

class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        unordered_map<int, int> birth_year;
        unordered_map<int, int> death_year;

        for (int year: birth) birth_year[year] ++;
        for (int year: death) death_year[year] ++;

        int people = 0;
        int maxPeople = -1;
        int maxPeopleYear = -1;
        FOR(year, 1900, 2001) {
            people += birth_year[year] - death_year[year - 1];
            if (people > maxPeople) {
                maxPeople = people;
                maxPeopleYear = year;
            }
        }
        return maxPeopleYear;
    }
};