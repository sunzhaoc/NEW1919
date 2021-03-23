/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-20 22:22:35
 * @LastEditTime: 2021-03-23 15:25:00
 * @FilePath: \Leetcode\1797.Design Authentication Manager.cpp
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



class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {

    }
    
    void generate(string tokenId, int currentTime) {

    }
    
    void renew(string tokenId, int currentTime) {

    }
    
    int countUnexpiredTokens(int currentTime) {

    }
};


/*
RESULT: Accept
TIME:    156ms    BEAT: 100.00%    O(n) = 
MEMORY: 29.2MB    BEAT: 100.00%    O(n) = 
LAST EDIT TIME: 2021-03-20 23:26:08
Description: 
*/

class AuthenticationManager {
public:
    unordered_map<string, pair<int, int>> record;
    int ttl;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        record[tokenId] = {currentTime, currentTime + ttl};
    }
    
    void renew(string tokenId, int currentTime) {
        if (record.find(tokenId) != record.end()) {
            if (record[tokenId].second > currentTime) {
                record[tokenId] = {currentTime, currentTime + ttl};
            }
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int res = 0;
        for (auto [k, v]: record) {
            int end = v.second;
            if (end > currentTime) res ++;
        }
        return res;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */