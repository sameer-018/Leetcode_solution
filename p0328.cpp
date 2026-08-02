//Odd Even Linked List

// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, 
// and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// Note that the relative order inside both the even and odd groups should remain as it was in the input.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        if(!head->next->next) return head;
        bool flag = true;
        ListNode *oddptr, *evenptr, *mover;
        oddptr = head;
        evenptr = head->next;
        ListNode *evenhead = evenptr;
        mover = evenptr->next;
        while(mover){
            if(flag){
                oddptr->next = mover;
                oddptr = mover;
                flag = false;
            }
            else {
                evenptr->next = mover;
                evenptr = mover;
                flag = true;
            }
            mover = mover->next;
        }
        evenptr->next = nullptr;
        oddptr->next = evenhead;
        return head;
    }
};
 