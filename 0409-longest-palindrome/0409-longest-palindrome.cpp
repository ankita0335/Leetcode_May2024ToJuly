class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char>st;
        int ans=0;
        st.insert(s[0]);
        int n=s.length();
        for(int i=1;i<n;i++)
        {
            if(st.find(s[i])!=st.end())
            {
                ans+=2;
                st.erase(s[i]);
            }
            else
            {
                st.insert(s[i]);
            }
        }
        if(!st.empty())
        {
            ans+=1;
        }
        return ans;
    }
};