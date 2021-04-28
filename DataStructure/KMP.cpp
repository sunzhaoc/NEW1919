/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-27 14:29:35
 * @LastEditTime: 2021-04-27 20:49:59
 * @FilePath: \Leetcode\DataStructure\KMP.cpp
 */

#include <bits/stdc++.h>
using namespace std;

/*
相关题目：
    LeetCode 28. 实现 strStr()
    https://leetcode-cn.com/problems/implement-strstr/
    Leetcode 1392. 最长快乐前缀
    https://leetcode-cn.com/problems/longest-happy-prefix/
    831. KMP字符串
    https://www.acwing.com/problem/content/833/

时间复杂度：O(m + n) 
空间复杂度：O(m)
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        vector<int> ne(m);

        // 计算next
        for (int i = 1, j = 0; i < m; i ++) {
            while (j && needle[i] != needle[j]) j = ne[j - 1];
            if (needle[i] == needle[j]) j ++;
            ne[i] = j;
        }

        // KMP
        for (int i = 0, j = 0; i < n; i ++) {
            while (j && haystack[i] != needle[j]) j = ne[j - 1];
            if (haystack[i] == needle[j]) j ++;
            if (j == m) return i - m + 1; // 如果有多个的话，把结果加进一个数组就行。
        }
        return -1;
    }
};
