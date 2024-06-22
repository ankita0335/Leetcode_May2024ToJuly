class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int c=0,currs=0;
        mp[currs]=1;
        for(int i=0;i<n;i++) 
        {
            currs+=(nums[i]%2); 
            if(mp.count(currs-k)) 
            {
                c+=mp[currs-k];
            }
            mp[currs]++;
        }
        return c;
    }
};

