class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customer) {
        int n=customer.size();
        long long sum=0;
        long long res=0;
        for(int i=0;i<n;i++)  //(1,2)      --- (2,5)
        {
            if(sum>customer[i][0])         //3>2        //8>4
            {
                sum=sum+customer[i][1];     //8(3+5)    //8+3=11
            }
            else
                sum=customer[i][0]+customer[i][1];
            
            res=res+sum-customer[i][0]; //2+6+7
        }
        return static_cast<double>(res)/n;
    }
};