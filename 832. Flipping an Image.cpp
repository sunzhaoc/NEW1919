/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-02 20:48:17
 * @LastEditTime: 2021-03-02 21:28:35
 * @FilePath: \Leetcode\832.Flipping an Image.cpp
 */
/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;


/*
RESULT: Accept
TIME:     8ms    BEAT: 35.22%    O(n) = mn
MEMORY: 8.4MB    BEAT: 12.77%    O(n) = 1
USED TIME: 04:16
LAST EDIT TIME: 2021年3月2日21:3:58
Description: 并不需要事先对A的每一行进行reverse，然后再取反，这样只会增加遍历A的次数。两步可以同时进行！
*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int row = image.size(), col = image[0].size();
        
        for (int i = 0; i < row; i ++) {
            for (int j = 0, k = col - 1; j <= k; j ++, k --) {    // 这里用j <= k而不是j < k因为有条件：反转图像，如果仅仅是水平翻转，则两种都可以。
                int A = !image[i][j], B = !image[i][k];    // python 这是用的是异或操作。
                image[i][j] = B, image[i][k] = A;
            }
        }

        return image;
    }
};


/*
RESULT: Accept
TIME:    12ms    BEAT: 35.22%    O(n) = nm
MEMORY: 8.6MB    BEAT:  8.29%    O(n) = 1
USED TIME: 02:41
LAST EDIT TIME: 2021年3月2日20:51:57
Description: 
*/

// class Solution {
// public:
//     vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
//         for (int i = 0; i < image.size(); i ++) {
//             reverse(image[i].begin(), image[i].end());
//         }
//         for (int i = 0; i < image.size(); i ++) {
//             for (int j = 0; j < image[0].size(); j ++) {
//                 image[i][j] = image[i][j] == 0 ? 1 : 0;
//             }
//         }
//         return image;
//     }
// };


int main() {
    Solution sol;
    vector<vector<int>> image = {{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    vector<vector<int>> ans = sol.flipAndInvertImage(image);
    for (int i = 0; i < ans.size(); i ++) {
        for (int j = 0; j < ans[0].size(); j ++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}

// @lc code=end

