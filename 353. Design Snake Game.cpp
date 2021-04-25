/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-16 13:58:40
 * @LastEditTime: 2021-04-16 14:31:28
 * @FilePath: \Leetcode\353. Design Snake Game.cpp
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
using VDD = vector<VD>;
using VS = vector<string>;
using VVS = vector<VS>;


/*
RESULT: Accept
TIME:    128ms    BEAT: 84.91%    O(n) = 
MEMORY: 56.5MB    BEAT: 94.34%    O(n) = 
USED TIME: 30:11
LAST EDIT TIME: 2021年4月16日14:30:40
Description: 
*/

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    deque<PII> snake;
    int row, col;
    int id_food = 0;
    VVI food;
    SnakeGame(int width, int height, vector<vector<int>>& snakefood) {
        row = height;
        col = width;
        food = snakefood; 
        snake.PB(MP(0, 0));
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int x = snake.back().F;
        int y = snake.back().S;
        auto axis = dirMove(direction, x, y);
        
        if (axis.F < 0 || axis.S < 0 || axis.F >= row || axis.S >= col) return -1;
        if (id_food < SZ(food) && axis.F == food[id_food][0] && axis.S == food[id_food][1]) {
            snake.PB(MP(axis.F, axis.S));
            id_food ++;
            return SZ(snake) - 1;
        }
        snake.pop_front();
        for (auto it = snake.begin(); it != snake.end(); it ++) if (*it == axis) return -1;
        snake.PB(MP(axis.F, axis.S));
        return SZ(snake) - 1;
    }

    PII dirMove(string dir, int x, int y) {
        if (dir == "U") x --;
        else if (dir == "D") x ++;
        else if (dir == "L") y --;
        else if (dir == "R") y ++;
        return MP(x, y);
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */