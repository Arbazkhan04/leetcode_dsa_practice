/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { 
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(list1 && list2){
            if(list1->val <=list2->val){
                head->next = list1;
                head = list1;
                list1 = list1->next;
            }
            else{
                head->next = list2;
                head = list2;
                list2 = list2->next;
            }
        }
        if(list1){
            head->next = list1;
            head = list1;
            list1= list1->next;
        }
        if(list2){
            head->next = list2;
            head = list2;
            list2 = list2->next;
        }
        return dummy->next;
    }
};