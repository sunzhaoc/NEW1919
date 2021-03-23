/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-18 21:00:54
 * @LastEditTime: 2021-03-23 10:26:47
 * @FilePath: \Leetcode\208.实现-trie-前缀树.cpp
 */
/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
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
TIME:     60ms    BEAT: 90.10%    O(n) = 
MEMORY: 43.7MB    BEAT: 64.31%    O(n) = 
LAST EDIT TIME: 2021年3月23日10:26:29
Description: 知识点不清楚。
*/

class Trie {
public:
    bool isEnd;
    Trie* next[26];
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char c: word) {
            if (node->next[c - 'a'] == nullptr) node->next[c - 'a'] = new Trie();
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char c: word) {
            node = node->next[c - 'a'];
            if (node == nullptr) return false;
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c: prefix) {
            node = node->next[c - 'a'];
            if (node == nullptr) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

