/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-09 16:00:40
 * @LastEditTime: 2021-03-09 16:22:41
 * @FilePath: \Leetcode\244.Shortest Word Distance II.cpp
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
TIME:     40ms    BEAT: 82.61%    O(n) = 
MEMORY: 18.8MB    BEAT: 40.18%    O(n) = 
USED TIME: 16:52
LAST EDIT TIME: 2021年3月9日16:18:31
Description: 用哈希表。
*/

class WordDistance {
public:
    unordered_map<string, vector<int>> words;
    WordDistance(vector<string>& word) {
        for (int i = 0; i < word.size(); i ++) {
            words[word[i]].emplace_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int p1 = 0, p2 = 0;
        int res = INT_MAX;

        while (p1 < words[word1].size() && p2 < words[word2].size()) {
            res = min(res, abs(words[word1][p1] - words[word2][p2]));
            if (words[word1][p1] > words[word2][p2]) p2 ++;
            else p1 ++;
        }

        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
