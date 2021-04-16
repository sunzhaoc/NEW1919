/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-09 15:27:50
 * @LastEditTime: 2021-03-09 15:59:39
 * @FilePath: \Leetcode\243.Shortest Word Distance.cpp
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:     12ms    BEAT: 84.39%    O(n) = 
MEMORY: 11.4MB    BEAT: 14.20%    O(n) = 
USED TIME: 28:45
LAST EDIT TIME: 2021年3月9日15:57:57
Description: 我也不知道为什么会写这么长时间。
*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1;
        int res = words.size();
        for (int i = 0; i < words.size(); i ++) {
            if (words[i] == word1) {
                p1 = i;
            }
            else if (words[i] == word2) {
                p2 = i;
            }

            if (p1 != -1 && p2 != -1) {
                res = min(res, abs(p1 - p2));
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    // vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    // int ans = sol.shortestDistance(words, "makes", "coding");
    // vector<string> words = {"a", "c", "b", "a"};
    // int ans = sol.shortestDistance(words, "b", "a");
    vector<string> words = {"a", "b"};
    int ans = sol.shortestDistance(words, "a", "b");
    cout << ans << endl;
    system("pause");
    return 0;
}

