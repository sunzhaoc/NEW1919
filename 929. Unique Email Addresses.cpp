/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-04 15:36:58
 * @LastEditTime: 2021-04-04 15:50:47
 * @FilePath: \Leetcode\929.Unique Email Addresses.cpp
 */
/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
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
TIME:     24ms    BEAT: 92.55%    O(n) = 
MEMORY: 14.7MB    BEAT: 26.32%    O(n) = 
USED TIME: 10:47
LAST EDIT TIME: 2021年4月4日15:50:44
Description: Easy
*/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> map;
        for (string email: emails) {
            string add = "";
            int id = email.length() - 1;
            while (email[id] != '@') {
                add = email[id] + add;
                id --;
            }
            add = "@" + add;
            id = 0;
            string add2 = "";
            while (email[id] != '@' && email[id] != '+') {
                if (email[id] == '.') {
                    id ++;
                    continue;
                }
                add2 += email[id];
                id ++;
            }
            add = add + add2;
            map.insert(add);
        }
        return map.size();
    }
};

// @lc code=end

