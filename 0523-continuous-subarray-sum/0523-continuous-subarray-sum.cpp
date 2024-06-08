class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int subSum=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            subSum+=nums[i];
            sum=subSum%k;
            if(mp.find(sum)!=mp.end())
            {
                if(i-mp[sum]>=2)
                {
                    return true;
                }
            }
            else
               mp[sum]=i;
        }
        return false;
    }
};