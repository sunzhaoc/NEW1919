/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-16 15:19:16
 * @LastEditTime: 2021-03-16 15:35:08
 * @FilePath: \Leetcode\demp.cpp
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
TIME:     212ms    BEAT: 96.59%    O(n) = 
MEMORY: 109.6MB    BEAT: 96.85%    O(n) = 
USED TIME: 10:25
LAST EDIT TIME: 2021年3月16日15:34:55
Description: 
*/

class AnimalShelf {
public:
    queue<pair<int, int>> cat;
    queue<pair<int, int>> dog;
    int time = 0;
    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal) {
        if (animal[1] == 0) cat.push({animal[0], time});
        else dog.push({animal[0], time});
        time ++;
    }
    
    vector<int> dequeueAny() {
        if (dog.empty() && cat.empty()) return {-1, -1};
        if (dog.empty()) {
            vector<int> tmp = {cat.front().first, 0};
            cat.pop();
            return tmp;
        } 
        if (cat.empty()) {
            vector<int> tmp = {dog.front().first, 1};
            dog.pop();
            return tmp;
        }
        else {
            if (dog.front().second < cat.front().second) {
                vector<int> tmp = {dog.front().first, 1};
                dog.pop();
                return tmp;
            }
            else {
                vector<int> tmp = {cat.front().first, 0};
                cat.pop();
                return tmp;
            }
        }
    }
    
    vector<int> dequeueDog() {
        if (dog.empty()) return {-1, -1};

        vector<int> tmp = {dog.front().first, 1};
        dog.pop();
        return tmp;
    }
    
    vector<int> dequeueCat() {
        if (cat.empty()) return {-1, -1};
        vector<int> tmp = {cat.front().first, 0};
        cat.pop();
        return tmp;
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */