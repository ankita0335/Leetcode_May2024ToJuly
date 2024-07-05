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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>res;
        vector<int>ans;
        int c=2;
        ListNode* prev=head;
        ListNode* curr=prev->next;
        ListNode* nextt=curr->next;
        while(nextt)
        {
            if(((prev->val>curr->val) && (nextt->val>curr->val)) ||
            ((prev->val< curr->val) && (nextt->val<curr->val)))
            {
                res.push_back(c);
            }
            prev=prev->next;
            curr=curr->next;
            nextt=nextt->next;
            c++;
        }
        if(res.size()<2)
        {
            return {-1,-1};
        }
        int n=res.size();
        int mini=INT_MAX;
        int maxi=res[n-1]-res[0];
        for(int i=0;i<n-1;i++)
        {
            int checkval=res[i+1]-res[i];
            if(checkval<mini)
                mini=checkval;
        }
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};