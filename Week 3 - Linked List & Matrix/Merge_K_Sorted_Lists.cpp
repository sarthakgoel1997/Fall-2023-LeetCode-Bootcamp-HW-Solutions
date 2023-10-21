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
    ListNode *merge2Lists(ListNode *head1, ListNode *head2) {
        if(head1 == NULL)
            return head2;
        
        if(head2 == NULL)
            return head1;
        
        ListNode *ans;
        if(head1->val <= head2->val) {
            ans = head1;
            ans->next = merge2Lists(head1->next, head2);
        }
        else {
            ans = head2;
            ans->next = merge2Lists(head1, head2->next);
        }
        return ans;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = NULL;
        for(int i=0; i<lists.size(); i++)
            ans = merge2Lists(ans, lists[i]);
        
        return ans;
    }
};