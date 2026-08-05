#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL) {}
};

// O(n) time complexity but O(n) space complexity
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> add;
        ListNode *mv1, *mv2;
        mv1 = headA;
        mv2 = headB;
        while(mv1){
            add.insert(mv1);
            mv1= mv1->next;
        }
        while(mv2){
            if(add.find(mv2) != add.end()){
                return mv2;
            }
            mv2 = mv2->next;
        }
        return nullptr;
    }
};

// O(n) timecomplexity but O(1) space complexity
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *mv1, *mv2;
        mv1 = headA;
        mv2 = headB;
        while(true){
            if(mv1 == mv2) return mv1;
            if(!mv1->next && !mv2->next && mv1!=mv2) return nullptr;

            if(!mv1->next) mv1 = headB;
            else mv1 = mv1->next;

            if(!mv2->next) mv2 = headA;
            else mv2 = mv2->next;
        }
        return nullptr;