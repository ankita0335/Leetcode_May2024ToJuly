class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>ex;
        int c=0;
        for(int i=0;i<heights.size();i++){
            ex.push_back(heights[i]);
        }
        sort(ex.begin(),ex.end());
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=ex[i]){
                c++;
            }
        }
        return c;
    }
};