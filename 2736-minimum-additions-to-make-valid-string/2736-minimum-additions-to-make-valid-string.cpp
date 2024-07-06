class Solution {
public:
    int addMinimum(string word) {
        int n=word.length();
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(i-3<n && word.substr(i,3)=="abc")
            {
                i+=2;
            }
            else if(i-2<n && (word.substr(i,2)=="ab" || word.substr(i,2)=="bc" || word.substr(i,2)=="ac") )
            {
                i++;
                c++;
            }
            else
                c+=2;
        }
        return c;
    }
};