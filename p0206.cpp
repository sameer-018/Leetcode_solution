//reverse the linked list
//Given the head of a singly linked list, reverse the list, and return the reversed list.

#include<iostream>
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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* mover = head;
        ListNode* temp = head->next;
        ListNode* nextadd;
        while(temp){
            nextadd = temp->next;
            temp->next = mover;
            mover = temp;
            temp = nextadd;
        }
        head->next=nullptr;
        return mover;
    }
};