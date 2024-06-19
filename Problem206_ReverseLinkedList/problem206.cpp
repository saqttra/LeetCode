/*

206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:

Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []

Constraints:

    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
    
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr, *next = nullptr;

        while (curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
        
    }
};


int main(void){
    // Test case
    Solution p206;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);

    ListNode* reversedHead = p206.reverseList(head);

    ListNode* current = reversedHead;
    std::cout << "Input: head = [";
    while (current != nullptr) {
        std::cout << current->val;
        current = current->next;
        if (current != nullptr) {
            std::cout << ",";
        }
    }
    std::cout << "]\n";
    
    current = reversedHead;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

