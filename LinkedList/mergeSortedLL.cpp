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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        
        ListNode* temp1 = l1;
        int size = 0;
        
        //joining two lists
        while(temp1 && temp1->next != NULL)
        {   size++;
            temp1 = temp1->next;
        }
        
        
        temp1->next = l2;
        if (temp1->val < l2->val)
            return l1;
        
        ListNode* temp2 = temp1->next;
        ListNode* prev1 = NULL;
        ListNode* prev2 = temp1;
        temp1 = l1;
        
        while(size >= 0 && temp1 && temp2)
        {
            if (temp1->val <= temp2->val)
            {
                prev1 = temp1;
                temp1 = temp1->next;
                size--;
            }
            else
            {
                prev2->next = temp2->next;
                temp2->next = temp1;
                
                if (prev1)
                    prev1->next = temp2;
                else
                    l1 = temp2;
                
                prev1 = temp2;
                temp2 = prev2->next;
            }
           
        }
        
        return l1;
    }
};