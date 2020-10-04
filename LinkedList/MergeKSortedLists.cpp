/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class myComparator 
{ 
public: 
    int operator() (const ListNode* p1, const ListNode* p2) 
    { 
        return p1->val > p2->val; 
    } 
}; 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
       if(lists.size()==0)return NULL;
        
       priority_queue<ListNode*,vector<ListNode*>,myComparator> q;
       ListNode* dummy = new ListNode(0);
       ListNode* temp=dummy;
       for(int i=0;i<lists.size();i++){
           if(lists[i])
           q.push(lists[i]);
       }
      while(!q.empty()){
          ListNode* x = q.top();
          temp->next=x;
          temp=temp->next;
          q.pop();
          x=x->next;
          if(x)
          q.push(x);
      }
      return dummy->next;
    }
};
