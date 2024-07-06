class Solution {
public:
    int bestClosingTime(string customers) {
        int ans=INT_MAX;
        int ansindex=0;
        int n=customers.size();
        vector<int>pre(n+1,0);
        vector<int>suff(n+1,0);
        pre[0]=0;
        suff[n]=0;
        for(int i=1;i<=n;i++)
        {
            if(customers[i-1]=='N')   //agr shop open hai and koi customer nhi aaya to
            {
                pre[i]=pre[i-1]+1;
            }
            else
                pre[i]=pre[i-1];
        }
        for(int i=n-1;i>=0;i--)
        {
            if(customers[i]=='Y') //If the shop is closed and a customer came
            {
                suff[i]=suff[i+1]+1;
            }
            else
                suff[i]=suff[i+1];
        }
        for(int i=0;i<=n;i++)
        {
            int mini=pre[i]+suff[i];
            if(mini<ans)
            {
                ans=mini;
                ansindex=i;
            }
        }
        return ansindex;
    }
};