//Merge two sorted linked list

// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* mv1;
        ListNode* mv2;
        ListNode* temp;
        if(!list1 && !list2){
            return nullptr;
        }
        if(!list1 && list2){
            return list2;
        }
        if(list1 && !list2){
            return list1;
        }
        if((list1->val)<(list2->val)){
            head = list1;
            mv1 = list1->next;
            mv2 = list2;
        }
        else{
            head = list2;
            mv1 = list1;
            mv2 = list2->next;
        }
        temp = head;

        while(mv1 && mv2){
            if((mv1->val)<(mv2->val)){
                temp->next = mv1;
                temp = mv1;
                mv1 = mv1->next;
            }
            else {
                temp->next = mv2;
                temp = mv2;
                mv2 = mv2->next;
            }
        }

        if(mv1){
            temp->next = mv1;
        }
        if(mv2){
            temp->next = mv2;
        }
        return head;
    }
};