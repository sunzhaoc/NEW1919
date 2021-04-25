/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-06 20:18:40
 * @LastEditTime: 2021-04-06 20:40:05
 * @FilePath: \Leetcode\379.Design Phone Directory.cpp
 */

#include <bits/stdc++.h>
using namespace std;


/*
RESULT: Accept
TIME:     52ms    BEAT: 52.69%    O(n) = 
MEMORY: 22.7MB    BEAT:  8.60%    O(n) = 
USED TIME: 10:59
LAST EDIT TIME: 2021年4月6日20:35:15
Description: 
不知道标签上的链表是什么意思，没 
*/

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    unordered_set<int> unused;
    unordered_set<int> used;
    int a;
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; i ++) unused.insert(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (unused.empty()) return -1;
        a = * unused.begin();
        unused.erase(* unused.begin());
        used.insert(a);
        return a;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (used.find(number) != used.end()) return false;
        return true;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        used.erase(number);
        unused.insert(number);
    }
};

