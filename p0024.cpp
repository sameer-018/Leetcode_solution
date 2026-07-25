// SWAP Nodes In Pairs

// Given a linked list, swap every two adjacent nodes and return its head.
// You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

#include <iostream>
#include <vector>
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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode *prev=head;
        ListNode *curr=prev->next;
        while(curr){
            swap(prev->val,curr->val);
            prev=curr->next;
            if(!prev) break;
            curr=prev->next;
        }
        return head;
    }
};