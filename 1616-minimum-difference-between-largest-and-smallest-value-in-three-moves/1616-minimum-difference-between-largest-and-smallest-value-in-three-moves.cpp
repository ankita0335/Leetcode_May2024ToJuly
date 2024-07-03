class Solution {
public:
    int minDifference(vector<int>& nums) {        //[5,3,2,4,6]
        int n = nums.size();                      //5
        if (n <= 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());            //[2,3,4,5,6]       
        int c1=nums[n-1]-nums[3];                  //1
        int c2=nums[n-4]-nums[0];                  //1
        int c3=nums[n-2]-nums[2];                  //1
        int c4=nums[n-3]-nums[1];                  //1
        return min({c1,c2,c3,c4});
    }
};
