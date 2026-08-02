// Remove Nth node From End of the Linked List

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode *mover = head;
        while(mover){
            size++;
            mover = mover->next;
        }
        if(size-n==0){
            head=head->next;
            return head;
        }
        int count = 0;
        ListNode *prev = head;
        mover = prev->next;
        while(mover){
            count++;
            if(count==size-n){
                prev->next = mover->next;
                delete mover;
                break;
            }
            prev = mover;
            mover = mover->next;
        }
        return head;
    }
};
