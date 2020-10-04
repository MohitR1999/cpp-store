class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        else if(head->next == NULL)
            return (new TreeNode(head->val));
        
        ListNode* fast = head->next->next;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        TreeNode* tree = new TreeNode(slow->next->val);
        tree->right = sortedListToBST(slow->next->next);
        slow->next = NULL;
        tree->left = sortedListToBST(head);
        
        return tree;
    }
};
