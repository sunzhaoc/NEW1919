/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-22 20:42:43
 * @LastEditTime: 2021-03-17 16:35:03
 * @FilePath: \Leetcode\733.Flood Fill.cpp
 */
/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <queue>
using namespace std;


/*
RESULT: Accept
TIME:     16ms    BEAT: 36.79%    O(n) = 
MEMORY: 13.4MB    BEAT: 56.45%    O(n) = 
LAST EDIT TIME: 2021年3月17日16:34:26
Description: Y总 DFS
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.empty() || image[0].empty() || image[sr][sc] == newColor) return image;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; 
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        for (int i = 0; i < 4; i ++) {
            int x = sr + dx[i], y = sc + dy[i];
            if (x >= 0 && x < image.size() && y >= 0 && y < image[0].size() && image[x][y] == oldColor) floodFill(image, x, y, newColor);
        }
        return image;
    }
};


/*
RESULT: Accept
TIME:     16ms    BEAT: 36.79%    O(n) = 
MEMORY: 13.9MB    BEAT: 17.01%    O(n) = 
USED TIME: 11:39
LAST EDIT TIME: 2021年3月17日16:12:56
Description: DFS 二刷。
*/

class Solution {
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        int target = image[sr][sc];
        return dfs(image, sr, sc, newColor, target);
    }

    vector<vector<int>> dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int target) {
        image[sr][sc] = newColor;
        if (sr - 1 >= 0 && image[sr - 1][sc] == target) image = dfs(image, sr - 1, sc, newColor, target);
        if (sr + 1 < image.size() && image[sr + 1][sc] == target) image = dfs(image, sr + 1, sc, newColor, target);
        if (sc - 1 >= 0 && image[sr][sc - 1] == target) image = dfs(image, sr, sc - 1, newColor, target);
        if (sc + 1 < image[0].size() && image[sr][sc+ 1] == target) image = dfs(image, sr, sc + 1, newColor, target);
        return image;
    }
};


/*
RESULT: Accept
TIME:      8ms    BEAT: 90.11%    O(n) = 
MEMORY: 13.4MB    BEAT: 54.04%    O(n) = 
USED TIME: 08:08
LAST EDIT TIME: 2021年3月17日15:54:38
Description: BFS 二刷。
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        int target = image[sr][sc];
        queue<pair<int, int>> point;
        point.push({sr, sc});
        while (point.size()) {
            int i = point.front().first;
            int j = point.front().second;
            point.pop();

            image[i][j] = newColor;
            if (i -1 >= 0 && image[i - 1][j] == target) point.push({i - 1, j});
            if (i + 1 < image.size() && image[i + 1][j] == target) point.push({i + 1, j});
            if (j - 1 >= 0 && image[i][j - 1] == target) point.push({i, j - 1});
            if (j + 1 < image[0].size() && image[i][j + 1] == target) point.push({i, j + 1});
        }
        return image;
    }
};


/*
RESULT: Accept
TIME:     12ms    BEAT: 90.49%    O(n) = mn
MEMORY: 13.4MB    BEAT: 88.22%    O(n) = mn
USED TIME: 06:08
LAST EDIT TIME: 2021年1月22日21:15:10
Description: DFS。
*/

// class Solution {
// public:
//     int numRow, numCol, target, colour;
//     vector<vector<int>> picture;
//     void dfs(int x, int y) {
//         picture[x][y] = colour;

//         if (x - 1 >= 0 && picture[x - 1][y] == target) dfs(x - 1, y);
//         if (x + 1 < numRow && picture[x + 1][y] == target) dfs(x + 1, y);
//         if (y - 1 >= 0 && picture[x][y - 1] == target) dfs(x, y - 1);
//         if (y + 1 < numCol && picture[x][y + 1] == target) dfs(x, y + 1);
//     }

//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//         numRow = image.size();
//         numCol = image[0].size();
//         target = image[sr][sc];
//         if (target == newColor) return image;
//         colour = newColor;
//         picture = image;
//         dfs(sr, sc);
//         return picture;
//     }
// };


/*
RESULT: Accept
TIME:     12ms    BEAT: 90.49%    O(n) = mn
MEMORY: 13.5MB    BEAT: 84.08%    O(n) = mn
USED TIME: 12:08
LAST EDIT TIME: 2021年1月22日21:3:25
Description: BFS。忘记考虑newcolor和target颜色相同会出现死循环的问题,第一次提交报错。
*/

// class Solution {
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//         int numRow = image.size();
//         int numCol = image[0].size();

//         int target = image[sr][sc];

//         queue<pair<int, int>> neighbour;
//         neighbour.push({sr, sc});
//         while (!neighbour.empty()) {
//             auto it = neighbour.front();
//             neighbour.pop();

//             int row = it.first, col = it.second;
//             image[row][col] = newColor;

//             if (row - 1 >= 0 && image[row - 1][col] == target) neighbour.push({row - 1, col});
//             if (row + 1 < numRow && image[row + 1][col] == target) neighbour.push({row + 1, col}); 
//             if (col - 1 >= 0 && image[row][col - 1] == target) neighbour.push({row, col - 1});
//             if (col + 1 < numCol && image[row][col + 1] == target) neighbour.push({row, col + 1});
//         }
        
//         return image;
//     }
// };

// @lc code=end

