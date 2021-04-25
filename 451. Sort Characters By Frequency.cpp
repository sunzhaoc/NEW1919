/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-31 14:04:54
 * @LastEditTime: 2021-03-31 14:24:09
 * @FilePath: \Leetcode\451.Sort Characters By Frequency.cpp
 */
/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
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
#include <stack>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 99.34%    O(n) = 
MEMORY: 9.2MB    BEAT: 31.30%    O(n) = 
USED TIME: 13:33
LAST EDIT TIME: 2021年3月31日14:18:59
Description: 二刷。python before.
*/

class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        vector<pair<string, int>> dict(128);
        for (char ch: s) {
            dict[ch].first += ch;
            dict[ch].second ++;
        }
        sort(dict.begin(), dict.end(), [] (const pair<string, int>& x, const pair<string, int>& y) {
            return x.second > y.second;
        });

        for (int i = 0; i < dict.size(); i ++) {
            if (dict[i].second == 0) break;
            else res += dict[i].first;
        }
        return res;
    }
};


int main() {
    Solution sol;
    string ans = sol.frequencySort("2a554442f544asfasssffffasss");
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

