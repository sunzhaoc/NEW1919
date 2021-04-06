/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-05 15:36:05
 * @LastEditTime: 2021-01-05 16:09:42
 * @FilePath: \Leetcode\剑指 Offer 35. 复杂链表的复制.cpp
 */


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:     20ms    BEAT: 48.70%    O(n) = 
MEMORY: 11.2MB    BEAT: 72.31%    O(n) = 
USED TIME: 14:55
Description: 哈希表。
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* cur = head;
        unordered_map<Node*, Node*> map;
        
        while (cur != nullptr)
        {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;        
        while (cur != nullptr) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->randow];
            cur = cur->next;
        }
        return map[head];
    }
};
