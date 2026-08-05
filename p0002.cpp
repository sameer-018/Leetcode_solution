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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyhead = new ListNode(-1);
        ListNode *curr = dummyhead;
        ListNode *mv1 = l1;
        ListNode *mv2 = l2;
        int carry = 0;
        while(mv1 || mv2){
            int sum = carry;
            if(mv1) sum += mv1->val;
            if(mv2) sum += mv2->val;
            carry = sum/10;

            ListNode *temp = new ListNode(sum%10);
            curr->next = temp;
            curr = temp;

            if(mv1) mv1 = mv1->next;
            if(mv2) mv2 = mv2->next; 
        }
        if(carry) {
            ListNode *temp = new ListNode(carry);
            curr->next = temp;
        }

        return dummyhead->next;
    }
};