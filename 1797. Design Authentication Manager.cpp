/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-20 22:22:35
 * @LastEditTime: 2021-03-23 15:38:37
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


/*
RESULT: Accept
TIME:     356ms    BEAT: 5.03%    O(n) = n^2
MEMORY: 315.9MB    BEAT: 5.02%    O(n) = 
LAST EDIT TIME: 2021年3月23日15:32:5
Description: Y总.
*/

typedef pair<string, int> PSI;

class AuthenticationManager {
public:
    vector<PSI> q;
    int T;
    AuthenticationManager(int timeToLive) {
        T = timeToLive;
    }
    
    void generate(string t, int c) {
        q.push_back({t, c});
    }
    
    void renew(string t, int c) {
        vector<PSI> w;
        for (auto& p: q) {
            if (p.second + T <= c) continue;
            if (p.first == t) w.push_back({t, c});
            else w.push_back(p);
        }
        q = w;
    }
    
    int countUnexpiredTokens(int c) {
        vector<PSI> w;
        for (auto& p: q) {
            if (p.second + T <= c) continue;
            w.push_back(p);
        }
        q = w;
        return q.size();
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