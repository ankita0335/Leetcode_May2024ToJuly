class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int left=0;
        int right=s.length()-1;
        int ans=0;
        while (left<right) 
        {
            if (s[left]==s[right]) 
            {
                left++;
                right--;
            } 
            else
            {
                int k=right;
                while(k>left&&s[k]!=s[left]) 
                {
                    k--;
                }
                if(k==left) 
                {
                    swap(s[left],s[left+1]);
                    ans++;
                }
                else 
                {
                    for(int j=k;j<right;j++) 
                    {
                        swap(s[j],s[j+1]);
                        ans++;
                    }
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};