// Sort Linked List

// Given the head of a linked list, return the list after sorting it in ascending order.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//O(nlogn) timecomplexity and O(n) space complexity
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        ListNode *mover = head;
        while(mover){
            nums.push_back(mover->val);
            mover = mover->next;
        }
        sort(nums.begin(),nums.end());
        mover = head;
        for(int i=0; i<nums.size(); i++){
            mover->val = nums[i];
            mover = mover->next;
        }
        return head;
    }
};

//O(nlogn) time complexity and O(1) space complexity
class Solution {
public:
    ListNode* MiddleNode(ListNode *head){
        if(!head) return head;
        ListNode *slow, *fast;
        slow = head;
        fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode *left, ListNode *right){
        ListNode *head, *mv1, *mv2;
        if(left->val < right->val){
            head = left;
            mv1 = left->next;
            mv2 = right;
        }
        else{
            head = right;
            mv1 = left;
            mv2 = right->next;
        }
        ListNode *curr = head;
        while(mv1 && mv2){
            if(mv1->val < mv2->val){
                curr->next = mv1;
                curr = mv1;
                mv1 = mv1->next;
            }
            else{
                curr->next = mv2;
                curr = mv2;
                mv2 = mv2->next;
            }
        }
        if(mv1) curr->next = mv1;
        if(mv2) curr->next = mv2;
        return head;
    }

    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;

        ListNode *mid = MiddleNode(head);
        ListNode *head2 = mid->next;
        mid->next = nullptr;

        ListNode *left = sortList(head);
        ListNode *right = sortList(head2);

        return merge(left, right);
    }
};