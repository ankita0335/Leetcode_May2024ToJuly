class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        //unordered_map<int,int>mp2;
        vector<int>v;
        for(auto i:nums1)
        {
            mp[i]++;
        }
        for(auto i:nums2)
        {
            if(mp[i]>0)
            {
                v.push_back(i);
                mp[i]--;
            }
        }
        return v;
    }
};