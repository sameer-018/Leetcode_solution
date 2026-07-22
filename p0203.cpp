// REMOVE AN ELEMENT FROM LINKED LIST

// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, 
//and return the new head.

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
    ListNode* removeElements(ListNode* head, int tar) {
        ListNode *curr, *prev;
        if(!head) return nullptr;
        while((head->val==tar) && (head)){
            ListNode* deleteNode = head;
            head = head->next;
            delete deleteNode;

            if(!head) return nullptr;
        }
        prev = head;
        curr = prev->next;
        while(curr){
            if(curr->val==tar){
                ListNode* deleteNode = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete deleteNode;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};