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