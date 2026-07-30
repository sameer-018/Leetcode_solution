//Chexk Palindrome in Linked List
// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

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
    //finding middle of linked list
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    //reversing linked list from middle
    ListNode* rev(ListNode* head) {
        ListNode* back = NULL;
        ListNode* front = NULL;
        while(head) {
            front = head->next;
            head->next = back;
            back = head;
            head = front;
        }
        return back;
    }
    // checking element from head and newreversed head
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* mid = middle(head);
        ListNode* right = rev(mid->next);

        ListNode* left = head;

        while(right) {
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
