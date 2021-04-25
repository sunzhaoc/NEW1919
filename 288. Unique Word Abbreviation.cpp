/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-14 22:39:38
 * @LastEditTime: 2021-01-14 22:56:35
 * @FilePath: \Leetcode\288.Unique Word Abbreviation.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:    152ms    BEAT: 100.00%    O(n) = n
MEMORY: 49.4MB    BEAT:  88.51%    O(n) = n
USED TIME: 13:50
LAST EDIT TIME: 2021年1月14日22:56:35
Description: 哈希表。
*/

class ValidWordAbbr {
public:
    unordered_map<string, vector<string>> map;

    ValidWordAbbr(vector<string>& dictionary) {
        string tmp;
        for (string i: dictionary) {
            if (i.length() == 2) map[i].push_back(i);
            else {
                tmp = i[0] + to_string(i.size() - 2) + i[i.length() - 1];
                map[tmp].push_back(i);
            }
        }
    }


    bool isUnique(string word) {
        string tmp;
        if (word.length() == 2) tmp = word;
        else tmp = word[0] + to_string(word.length() - 2) + word[word.length() - 1];

        if (map.find(tmp) == map.end()) return true;
        else {
            auto p = map.find(tmp);
            for (string i: p->second) {
                if (i != word) return false;
            }
            return true;
        }
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */