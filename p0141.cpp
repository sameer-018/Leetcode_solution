//Check Linked List cycle

// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

#include<iostream>
#include<vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int checkmover(vector<ListNode*> adr, ListNode* mv){
        for(int i=0; i<adr.size(); i++){
            if(adr[i]==mv) return 1;
        }
        return 0;
    }
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* mover;
        vector<ListNode*> memadd;
        mover = head;
        while(mover){
            if(checkmover(memadd, mover)){
                return true;
            }
            else{
                memadd.push_back(mover);
                mover = mover->next;
            }
        }
        return false;
    }
};