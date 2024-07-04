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
    ListNode* merge(ListNode* &ptr,ListNode* &curr) {
        curr=ptr->next;
        int sum=0;
        ListNode* res=new ListNode();
        if(ptr==nullptr || ptr->next==nullptr)
            return nullptr;
        while(curr!=nullptr && curr->val!=0)
        {
            sum+=curr->val;
            curr=curr->next;
            ptr=ptr->next;
        }
        ptr=ptr->next;
        res->val=sum;
        res->next=merge(ptr,curr);
        return res;
    }
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ptr=head;
        ListNode* curr=ptr->next;
        return merge(ptr,curr);
    }
};
