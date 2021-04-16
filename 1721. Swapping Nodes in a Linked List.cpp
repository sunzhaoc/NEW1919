/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-16 15:03:59
 * @LastEditTime: 2021-01-12 09:22:35
 * @FilePath: \Leetcode\1721.Swapping Nodes in a Linked List.cpp
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 


#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:    1196ms    BEAT: 100.00%    O(n) = 
MEMORY: 176.3MB    BEAT: 100.00%    O(n) = 
Description: lucifer1005的代码。
*/

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        ListNode* ptr = head;
        while (ptr) {
            len ++;
            ptr = ptr->next;
        }

        auto get_node = [=](int idx) {
            ListNode* ptr = head;
            for (int i = 0; i < idx - 1; ++i) {
                ptr = ptr->next;
            }
            return ptr;
        };

        auto left = get_node(k);
        auto right = get_node(len + 1 - k);
        swap(left->val, right->val);
        return head;
    }
};


/*
RESULT: Accept
TIME:    1116ms    BEAT: 100.00%    O(n) = 
MEMORY: 176.3MB    BEAT: 100.00%    O(n) = 
Description: Heltion的代码。
*/

// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k) {
//         int n = 0;
//         for (auto p = head; p; p = p->next) n += 1;
//         // 写成下面这种会容易理解一点。
//         // for (auto p = head; p = nullptr; p = p->next) n += 1;

//         auto a = head;
//         for (int i = 1; i < k; i ++) a = a->next;

//         auto b = head;
//         for (int i = 1; i < n - k + 1; i ++) b = b->next;

//         swap(a->val, b->val);
//         return head;
//     }
// };


/*
RESULT: Accept
TIME:   1084ms    BEAT: 100.00%    O(n) = 
MEMORY:  178MB    BEAT: 100.00%    O(n) = 
USED TIME: 42:56
Description: 
*/

// class Solution {
// public:
//     ListNode* node_left;
//     ListNode* node_left_father;
//     ListNode* node_right;
//     ListNode* node_right_father;
//     int length;
//     void dfs(ListNode* node, ListNode* node_father, int depth, int k) {
//         if (depth == k) {
//             node_left = node;
//             node_left_father = node_father;
//             return;
//         }
//         dfs(node->next, node, depth + 1, k);
//         return;
//     }


//     void dfs_length(ListNode* node, int depth) {
//         if (node->next == nullptr) {
//             length = depth;
//             return;
//         }
//         dfs_length(node->next, depth + 1);
//         return;
//     }

//     void dfs_right(ListNode* node, ListNode* node_father, int depth, int k) {
//         if (depth == k) {
//             node_right = node;
//             node_right_father = node_father;
//             return;
//         }
//         dfs_right(node->next, node, depth + 1, k);
//         return;
//     }

//     ListNode* swapNodes(ListNode* head, int k) {
//         dfs(head, nullptr, 1, k);
//         dfs_length(head, 1);
//         if (k == length-k+1) return head;
//         dfs_right(head, nullptr, 1, length - k + 1);

//         if (k == 1 && length > 2) {
//             node_right->next = node_left->next;
//             node_right_father->next = node_left;
//             node_left->next = nullptr;
//             return node_right;
//         }
//         if (k == length && k > 2) {
            
//             node_left->next = node_right->next;
//             node_left_father->next = node_right;
//             node_right->next = nullptr;
//             return node_left;
//         }
//         if (k % 2 == 1 && length == 2) {
//             ListNode* temp = node_left;
//             node_left->next = nullptr;
//             node_right->next = temp;
//             return node_right;
//         }
//         if (k % 2 == 0 && length == 2) {
//             node_left->next = node_right;
//             node_right->next = nullptr;
//             return node_left;
//         }
//         node_left_father->next = node_right;
//         node_right_father->next = node_left;
//         ListNode* temp = node_left->next;
//         node_left->next = node_right->next;
//         node_right->next = temp;
//         return head;
//     }
// };