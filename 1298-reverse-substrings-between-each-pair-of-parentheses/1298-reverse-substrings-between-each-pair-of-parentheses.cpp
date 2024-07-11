class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<char>st;
        int i=0;
        while(i<n)
        {
            if(s[i]!='(' && s[i]!=')')
            {
                st.push(s[i]);
            }
            else if(s[i]=='(')
            {
                st.push(' ');
            }
            else if(s[i]==')')
            {
                string s1="";
                int j=0;
                while(st.top()!=' ')
                {
                    s1=s1+st.top();
                    st.pop();
                }
                st.pop();
                while(j<s1.size())
                {
                    st.push(s1[j]);
                    j++;
                }
            }
            i++;
        }
        string s2="";
        while(!st.empty())
        {
            s2.push_back(st.top());
            st.pop();
        }
        reverse(s2.begin(),s2.end());
        return s2;
    }
};