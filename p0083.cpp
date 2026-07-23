// //Remove Duplicate Element from Sorted linked list
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode *curr, *prev;
        prev = head;
        curr = prev->next;
        while(curr){
            if(prev->val==curr->val){
                prev->next=curr->next;
                ListNode* deleteNode = curr;
                curr = curr->next;
                delete deleteNode;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};